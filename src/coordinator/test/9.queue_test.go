package test

import (
	"falcon_platform/cache"
	"fmt"
	"testing"
)

func TestQueue(t *testing.T) {

	a := cache.QItem{}

	res := cache.Serialize(&a)

	res2 := cache.Deserialize(res)

	fmt.Println(res)

	fmt.Println("---------------------------------------------------------------")

	fmt.Println(res2.AddrList)
	fmt.Println(res2.JobId)

}
