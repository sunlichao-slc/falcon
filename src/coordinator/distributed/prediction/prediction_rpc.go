package prediction

import (
	"coordinator/common"
	"coordinator/distributed/taskmanager"
	"coordinator/logger"
	"net/rpc"
)

func RunPrediction(masterAddress, predAddress string){

	msvc := new(ModelService)
	msvc.InitRpcBase(predAddress)
	msvc.Name = common.ModelService
	msvc.pm = taskmanager.InitSubProcessManager()

	rpcSvc := rpc.NewServer()
	err := rpcSvc.Register(msvc)
	if err!= nil{
		logger.Do.Printf("%s: start Error \n", msvc.Name)
		return
	}

	logger.Do.Printf("%s: register to masterAddress=%s \n", msvc.Name, predAddress)

	msvc.register(masterAddress)

	msvc.StartRPCServer(rpcSvc, true)

}