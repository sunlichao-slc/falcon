package models

import (
	"time"
)

type JobRecord struct {
	JobId    uint   `gorm:"primary_key;auto_increment"`

	AppId	 uint // Application id

	JobName  string `gorm:"type:varchar(256)"`
	UserID   uint

	PartyIds  string  `gorm:"type:varchar(1024)"`
	TaskInfos string `gorm:"type:varchar(1024)"`

	// 0: init, 1: running, 2:successful, 3: failed, 4: killed
	Status        uint

	TaskNum       uint //?
	FlSetting     uint

	ErrorMsg      string `gorm:"type:varchar(256)"`
	JobDecs       string `gorm:"type:varchar(4096)"`
	JobResult     string `gorm:"type:varchar(4096)"`
	IsDelete      uint
	CreateTime    time.Time `gorm:"type:datetime"`
	UpdateTime    time.Time `gorm:"type:datetime"`
	DeleteTime    time.Time `gorm:"type:datetime"`
	ExtInfo       string    `gorm:"type:varchar(1024)"`
	MasterAddr string    `gorm:"type:varchar(256)"`
}

type TaskRecord struct {
	ID         uint `gorm:"primary_key;AUTO_INCREMENT"`
	JobID      uint `gorm:"unique_index"`
	//TaskId     uint
	TaskName   string `gorm:"type:varchar(256)"`
	PartyIds   string `gorm:"type:varchar(256)"`
	Status     uint
	ErrorMsg   string `gorm:"type:varchar(1024)"`
	TaskDecs   string `gorm:"type:varchar(1024)"`
	TaskResult string `gorm:"type:varchar(1024)"`
	IsDelete   uint
	CreateTime time.Time
	UpdateTime time.Time
	DeleteTime time.Time
	ExtInfo    string `gorm:"type:varchar(4096)"`
}


type ServiceRecord struct {
	ID         uint   `gorm:"primary_key;AUTO_INCREMENT"`
	JobID      uint   `gorm:"unique_index"`
	MasterAddr string `gorm:"type:varchar(256)"`
	WorkerAddr string `gorm:"type:varchar(256)"`
}


type PortRecord struct {
	ID         uint   `gorm:"primary_key;AUTO_INCREMENT"`
	NodeId	   uint
	Port       uint   `gorm:"unique_index"`
	IsDelete   uint
}


type User struct {
	UserID uint   `gorm:"primary_key;AUTO_INCREMENT"`
	Name   string `gorm:"type:varchar(256)"`
}

type PartyServer struct {
	ID           uint   `gorm:"primary_key;AUTO_INCREMENT"`
	PartyServerAddr string `gorm:"type:varchar(256)"`
	Port string `gorm:"type:varchar(256)"`
}

type TestTable struct {
	ID   uint   `gorm:"primary_key;AUTO_INCREMENT"`
	Name string `gorm:"type:varchar(256)"`
}

//////////////////////////////////////////////////////////////////
///////////////////// PartyServerDatabase  //////////////////////////
//////////////////////////////////////////////////////////////////


type ExecutionRecord struct {
	ID         uint `gorm:"primary_key;AUTO_INCREMENT"`
	TapeId     uint
	TapeName   string `gorm:"type:varchar(256)"`
	Status     uint
	ErrorMsg   string `gorm:"type:varchar(4096)"`
	TapeDecs   string `gorm:"type:varchar(4096)"`
	IsDelete   uint
	CreateTime time.Time
	UpdateTime time.Time
	DeleteTime time.Time
	ExtInfo    string `gorm:"type:varchar(4096)"`
}

type ModelRecord struct {
	ID          uint `gorm:"primary_key;AUTO_INCREMENT"`
	//ModelId     uint									//model编号，与job编号相同
	JobId       uint									//外键job id

	ModelName   string `gorm:"type:varchar(256)"`		//model名称，LR etc.
	ModelDecs   string `gorm:"type:varchar(256)"`		//model描述，与job名称相同

	//ModelData   string `gorm:"type:varchar(4096)"`	// model参数

	PartyNumber uint									//参与⽅个数
	PartyIds    string `gorm:"type:varchar(256)"`		//参与⽅ids

	IsTrained	uint
	IsPublished uint
	IsDelete    uint

	CreateTime  time.Time
	UpdateTime  time.Time
	DeleteTime  time.Time
	ExtInfo     string `gorm:"type:varchar(4096)"`
}


type ModelServiceInfo struct {
	ID          		uint `gorm:"primary_key;AUTO_INCREMENT"`

	//ModelServiceId      uint								//model_service编号

	ModelServiceName   	string `gorm:"type:varchar(256)"`   //模型服务描述
	// 0: init, 1: running, 2:successful, 3: failed, 4: killed
	Status        		uint

	ModelId	 			uint  //外键模型id，标明哪个模型执⾏
	JobId    			uint  //外键模型id，标明哪个训练job

	IsPublished   		uint  //是否被发布
	IsDelete    		uint  //记录是否被删除

	CreateTime  		time.Time
	UpdateTime  		time.Time
	DeleteTime  		time.Time
	ExtInfo     		string `gorm:"type:varchar(4096)"`
}