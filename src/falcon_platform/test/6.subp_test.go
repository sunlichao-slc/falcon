package test

import (
	"context"
	"falcon_platform/distributed/taskmanager"
	"falcon_platform/logger"
	"fmt"
	"os/exec"
	"testing"
	"time"
)

func TestSubProc(t *testing.T) {
	logger.Log, logger.LogFile = logger.GetLogger("./TestSubProc")

	//out, err := exec.Command("python3", "/go/preprocessing.py", "-a=1", "-b=2").Output()
	//fmt.Println(out, err)

	cmd := exec.Command(
		"python3",
		"-u", "/Users/nailixing/GOProj/src/github.com/falcon/src/falcon_platform/falcon_ml/preprocessing.py",
		"-a=1", "-b=2", "-c=123")
	var envs []string

	pm := taskmanager.InitSubProcessManager()
	pm.Ctx, pm.Cancel = context.WithCancel(context.Background())

	go func() {
		for i := 8; i > 0; i-- {
			time.Sleep(time.Second * 1)
			logger.Log.Println("Before kill process", i)
		}
		pm.Cancel()
	}()

	el, e := pm.CreateResources(cmd, envs)
	logger.Log.Println(e, el)

	//logger.Log.Println("Worker:task model training start")
	//args = []string{"plot_out_of_core_classification.py", "-a 1 -b 1"}
	////
	//killed, e, el, ol = pm.ExecuteSubProc(dir, stdIn, commend, args, envs)
	//logger.Log.Println(killed, e, el, ol)

	time.Sleep(time.Second * 3)
}

func TestSubProcessShell(t *testing.T) {
	logger.Log, logger.LogFile = logger.GetLogger("./TestSubProc")

	commend := "./scripts/_create_runtime_master.sh master-6369386254669931332 30006 6369386254669931332 train"
	err := taskmanager.ExecuteBash(commend)
	fmt.Println(err)

	_ = taskmanager.ExecuteBash("ls")
	_ = taskmanager.ExecuteBash("pwd")

}