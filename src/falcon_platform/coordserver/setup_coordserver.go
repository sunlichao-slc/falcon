package coordserver

import (
	"context"
	"falcon_platform/common"
	"falcon_platform/coordserver/controller"
	"falcon_platform/coordserver/router"
	"falcon_platform/coordserver/view"
	"falcon_platform/logger"
	"log"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/gorilla/handlers"
)

func SetupCoordServer(nConsumer int) {
	defer logger.HandleErrors()

	// set up views
	view.LoadTemplates("./coordserver/view/templates/*.html")

	// set up HTTP server routes
	r := router.NewRouter()

	// Set up Database
	logger.Log.Println("[coordinator server]: Init DataBase...")
	controller.CreateTables()
	if common.JobDatabase == common.DBMySQL {
		// initialize the mysql db
		controller.CreateSysPorts()
	}

	logger.Log.Println("[coordinator server]: Create admin user...")
	controller.CreateUser()

	// Set up Job Scheduler
	logger.Log.Println("[coordinator server]: Starting multi consumers...")
	jobScheduler := controller.Init(nConsumer)
	// multi-thread consumer
	for i := 0; i < nConsumer; i++ {

		go jobScheduler.Consume(i)
	}
	go jobScheduler.MonitorConsumers()

	// for logging and tracing
	http_logger := log.New(os.Stdout, "[http] ", log.LstdFlags)
	http_logger.Println("HTTP Server is starting...")

	// set up the HTTP server
	// modified from https://github.com/enricofoltran/simple-go-server/blob/master/main.go
	server := &http.Server{
		Addr: common.CoordAddr,
		// Pass instance of gorilla/mux in
		Handler: handlers.CombinedLoggingHandler(os.Stdout, r),
		// Handler:  logger.HttpTracing(logger.NextRequestID)(logger.HttpLogging(http_logger)(r)),
		ErrorLog: http_logger,
		// Good practice: enforce timeouts for servers to avoid Slowloris attacks
		ReadTimeout:  5 * time.Second,
		WriteTimeout: 10 * time.Second,
		IdleTimeout:  15 * time.Second,
	}

	// use a buffered channel for signal
	done := make(chan bool)
	// Set up channel on which to send signal notifications.
	// to accept graceful shutdowns
	quit := make(chan os.Signal, 1)
	signal.Notify(quit, os.Interrupt, syscall.SIGINT, syscall.SIGTERM, syscall.SIGKILL)

	go func() {
		<-quit

		logger.Log.Println("[coordinator server]: Stop multi consumers")

		jobScheduler.StopMonitor()
		logger.Log.Println("[coordinator server]: Monitor Stopped")

		for i := 0; i < nConsumer; i++ {
			jobScheduler.StopConsumer()
		}

		logger.Log.Println("[coordinator server]: Consumer Stopped")

		http_logger.Println("HTTP Server is shutting down...")

		ctx, cancel := context.WithTimeout(context.Background(), 30*time.Second)
		defer cancel()

		server.SetKeepAlivesEnabled(false)
		if err := server.Shutdown(ctx); err != nil {
			http_logger.Fatalf("Could not gracefully shutdown the server: %v\n", err)
			logger.Log.Fatal("[coordinator server]: Could not gracefully shutDown the server: ", err)
		}
		close(done)
	}()

	http_logger.Println("HTTP Server is ready to handle requests at", common.CoordAddr)
	logger.Log.Printf(
		"[coordinator server] listening on IP: %v, Port: %v\n",
		common.CoordIP,
		common.CoordPort)

	// ErrServerClosed is returned by the Server's Serve, ServeTLS, ListenAndServe, and ListenAndServeTLS methods
	// after a call to Shutdown or Close
	if err := server.ListenAndServe(); err != nil && err != http.ErrServerClosed {
		http_logger.Fatalf("Could not listen on %s: %v\n", common.CoordAddr, err)
		logger.Log.Fatal("[coordinator server]: Could not listen on ", common.CoordAddr, " err: ", err, "\n")
	}

	<-done
	http_logger.Println("HTTP Server stopped")
	logger.Log.Println("[coordinator server]: Server Stopped")
	os.Exit(0)
}