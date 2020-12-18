package coordserver

import (
	"context"
	"coordinator/coordserver/controller"
	md "coordinator/coordserver/middleware"
	rt "coordinator/coordserver/router"
	"coordinator/common"
	"coordinator/logger"
	"net/http"
	"os"
	"os/signal"
	"syscall"
)


func SetupHttp(nConsumer int) {
	defer logger.HandleErrors()
	mux := http.NewServeMux()

	md.SysLvPath = []string{common.Register, common.PartyServerAdd}

	//job
	mux.HandleFunc("/"+common.SubmitJob, md.AddRouter(rt.JobSubmit, http.MethodPost))
	mux.HandleFunc("/"+common.StopJob, md.AddRouter(rt.JobKill, http.MethodPost))
	mux.HandleFunc("/"+common.UpdateJobMaster, md.AddRouter(rt.JobUpdateMaster, http.MethodPost))
	mux.HandleFunc("/"+common.UpdateJobStatus, md.AddRouter(rt.JobUpdateStatus, http.MethodPost))
	mux.HandleFunc("/"+common.UpdateJobResInfo, md.AddRouter(rt.JobUpdateResInfo, http.MethodPost))

	mux.HandleFunc("/"+common.QueryJobStatus, md.AddRouter(rt.JobStatusQuery, http.MethodGet))

	//party server
	mux.HandleFunc("/"+common.Register, md.AddRouter(rt.UserRegister, http.MethodPost))
	mux.HandleFunc("/"+common.PartyServerAdd, md.AddRouter(rt.PartyServerAdd, http.MethodPost))
	mux.HandleFunc("/"+common.PartyServerDelete, md.AddRouter(rt.PartyServerDelete, http.MethodPost))
	mux.HandleFunc("/"+common.GetPartyServerPort, md.AddRouter(rt.GetPartyServerPort, http.MethodGet))

	// model serving
	mux.HandleFunc("/"+common.ModelUpdate, md.AddRouter(rt.ModelUpdate, http.MethodPost))

	// prediction service
	mux.HandleFunc("/"+common.InferencePublish, md.AddRouter(rt.PublishInference, http.MethodPost))
	mux.HandleFunc("/"+common.InferenceCreate, md.AddRouter(rt.CreateInference, http.MethodPost))
	mux.HandleFunc("/"+common.InferenceStatusUpdate, md.AddRouter(rt.UpdateInferenceStatus, http.MethodPost))

	// resource
	mux.HandleFunc("/"+common.AssignPort, md.AddRouter(rt.AssignPort, http.MethodGet))
	mux.HandleFunc("/"+common.AddPort, md.AddRouter(rt.AddPort, http.MethodPost))

	// run
	server := &http.Server{
		Addr:    "0.0.0.0:" + common.CoordPort,
		Handler: mux,
	}

	logger.Do.Println("HTTP: Updating table...")
	controller.CreateTables()
	controller.CreateSysPorts()

	logger.Do.Println("HTTP: Creating admin user...")
	controller.CreateUser()


	jobScheduler := controller.Init(nConsumer)

	done := make(chan os.Signal)
	signal.Notify(done, os.Interrupt, syscall.SIGINT, syscall.SIGTERM)
	go func() {

		<-done

		logger.Do.Println("HTTP: Stop multi consumers")

		jobScheduler.StopMonitor()
		logger.Do.Println("HTTP: Monitor Stopped")

		for i := 0; i < nConsumer; i++ {
			jobScheduler.StopConsumer()
		}

		//todo, this will shutdown the master thread at the same time
		// but the worker need to be stopped also??, add later ???

		logger.Do.Println("HTTP: Consumer Stopped")
		if err := server.Shutdown(context.Background()); err != nil {
			logger.Do.Fatal("HTTP: ShutDown the server", err)
		}
	}()

	logger.Do.Println("HTTP: Starting multi consumers...")

	// multi-thread consumer

	for i := 0; i < nConsumer; i++ {

		go jobScheduler.Consume(i)
	}
	go jobScheduler.MonitorConsumers()

	logger.Do.Println("HTTP: Starting HTTP server...")
	err := server.ListenAndServe()

	if err != nil {
		if err == http.ErrServerClosed {
			logger.Do.Print("HTTP: Server closed under request", err)
		} else {
			logger.Do.Fatal("HTTP: Server closed unexpected", err)
		}
	}

}
