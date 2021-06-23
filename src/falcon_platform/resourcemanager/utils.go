package resourcemanager

import (
	"falcon_platform/logger"
	"fmt"
	"io/ioutil"
	"math/rand"
	"net"
	"os/exec"
)

// get one port
func GetFreePort() (int, error) {
	addr, err := net.ResolveTCPAddr("tcp", "localhost:0")
	if err != nil {
		return 0, err
	}

	l, err := net.ListenTCP("tcp", addr)
	if err != nil {
		return 0, err
	}
	defer logger.Log.Println(l.Close())
	return l.Addr().(*net.TCPAddr).Port, nil
}

// get many ports
func GetFreePorts(count int) ([]int, error) {
	var ports []int
	for i := 0; i < count; i++ {
		addr, err := net.ResolveTCPAddr("tcp", "localhost:0")
		if err != nil {
			return nil, err
		}

		l, err := net.ListenTCP("tcp", addr)
		if err != nil {
			return nil, err
		}
		ports = append(ports, l.Addr().(*net.TCPAddr).Port)
		logger.Log.Println(l.Close())
	}
	return ports, nil
}

// get one port
func GetFreePort4K8s() (int, error) {
	min := 30000
	max := 32767
	p := rand.Intn(max-min) + min

	var addr *net.TCPAddr
	var l *net.TCPListener
	var err error

	for {
		addr, err = net.ResolveTCPAddr("tcp", "localhost:"+fmt.Sprintf("%d", p))
		if err != nil {
			return 0, err
		}

		l, err = net.ListenTCP("tcp", addr)
		if err != nil {
			p++
		} else {
			logger.Log.Println(l.Close())
			return p, nil
		}
	}
}

type OutStream struct{}

func (out OutStream) Write(p []byte) (int, error) {
	fmt.Printf("[SubProcessManager]: subprocess' output log ----------> %s", string(p))
	return len(p), nil
}

func ExecuteBash(command string) error {
	// return cmd object
	logger.Log.Println("[SubProcessManager]: execute bash ::", command)

	cmd := exec.Command("bash", "-c", command)

	stderr, _ := cmd.StderrPipe()
	stdout, _ := cmd.StdoutPipe()

	if err := cmd.Start(); err != nil {
		logger.Log.Println("[SubProcessManager]: executeBash: Start error ", err)
		return err
	}
	errLog, _ := ioutil.ReadAll(stderr)
	outLog, _ := ioutil.ReadAll(stdout)

	logger.Log.Println("[SubProcessManager]: executeBash: error log is ", string(errLog))
	logger.Log.Println("[SubProcessManager]: executeBash: out put is ", string(outLog))
	outErr := cmd.Wait()
	return outErr

}

func ExecuteCmd(cmd *exec.Cmd) error {
	// cmd

	logger.Log.Printf("[ExecuteCmd]: Execute cmd \"%s\"", cmd.String())

	stderr, _ := cmd.StderrPipe()
	stdout, _ := cmd.StdoutPipe()

	if err := cmd.Start(); err != nil {
		logger.Log.Println("[ExecuteCmd]: Error: ", err)
		return err
	}
	errLog, _ := ioutil.ReadAll(stderr)
	outLog, _ := ioutil.ReadAll(stdout)

	logger.Log.Println("[ExecuteCmd]: ErrorLog is ", string(errLog))
	logger.Log.Println("[ExecuteCmd]: OutPut is ", string(outLog))
	outErr := cmd.Wait()

	return outErr
}