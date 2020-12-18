package controller

import (
	"coordinator/cache"
	"coordinator/common"
	"coordinator/coordserver/entity"
	dist "coordinator/distributed"
	"coordinator/logger"
	"encoding/json"
)




func CreateInference(pJob common.InferenceJob, ctx *entity.Context) bool {

	ctx.JobDB.Tx = ctx.JobDB.Db.Begin()

	e1, trainJob := ctx.JobDB.JobGetByJobID(pJob.JobId)

	e2, JobInfo := ctx.JobDB.JobInfoGetById(trainJob.JobInfoID)
	e3, model := ctx.JobDB.ModelGetByID(pJob.JobId)
	ctx.JobDB.Commit([]error{e1, e2, e3})

	// if train is not finished, return
	if model.IsTrained == 0{
		return false
	}

	// if train is not finished, else create a inference job
	ctx.JobDB.Tx = ctx.JobDB.Db.Begin()
	e1, _ = ctx.JobDB.CreateInference(model.ID, pJob.JobId)
	ctx.JobDB.Commit(e1)

	var pInfo []common.PartyInfo
	var TaskInfo common.Tasks

	err := json.Unmarshal([]byte(JobInfo.PartyIds), &pInfo)
	err2 := json.Unmarshal([]byte(JobInfo.TaskInfo), &TaskInfo)
	if err != nil || err2!=nil {
		panic("json.Unmarshal(PartyIds or TaskInfo) error")
	}

	var inferencePartyInfo []common.PartyInfo

	DataInfo := pJob.DataInfo

	for _, info := range DataInfo{
		for _, v := range pInfo{

			if info.ID == v.ID{
				tmp := common.PartyInfo{}
				tmp.ID = info.ID
				tmp.Addr = v.Addr
				tmp.PartyType = v.PartyType
				tmp.PartyPaths = common.PartyPath{}
				tmp.PartyPaths.DataInput = info.InferenceDataPath
				inferencePartyInfo = append(inferencePartyInfo, tmp)
			}
		}
	}


	addresses := common.ParseAddress(inferencePartyInfo)

	qItem := new(cache.QItem)
	qItem.AddrList = addresses
	qItem.JobId = trainJob.JobId
	qItem.JobName = JobInfo.JobName
	qItem.JobFlType = JobInfo.FlSetting
	qItem.ExistingKey = JobInfo.ExistingKey
	qItem.PartyNums = JobInfo.PartyNum
	qItem.PartyInfo = pInfo
	qItem.Tasks = TaskInfo

	go func(){
		defer logger.HandleErrors()
		dist.SetupDist(qItem, common.InferenceWorker)
	}()

	return true

}


func UpdateInference(jobName string, ctx *entity.Context) {
	userId := ctx.UsrId

	ctx.JobDB.Tx = ctx.JobDB.Db.Begin()

	e1, JobInfo := ctx.JobDB.LatestJobInfoIdGetByUserIDAndJobName(userId, jobName)
	e2, job := ctx.JobDB.JobGetByJobInfoID(JobInfo.Id)
	e3, model := ctx.JobDB.ModelGetByID(job.JobId)
	e4, _ := ctx.JobDB.CreateInference(model.ID, job.JobId)
	ctx.JobDB.Commit([]error{e1, e2, e3, e4})

	var pInfo []common.PartyInfo
	var TaskInfo common.Tasks

	err := json.Unmarshal([]byte(JobInfo.PartyIds), &pInfo)
	err2 := json.Unmarshal([]byte(JobInfo.TaskInfo), &TaskInfo)
	if err != nil || err2!=nil {
		panic("json.Unmarshal(PartyIds or TaskInfo) error")
	}

	addresses := common.ParseAddress(pInfo)

	qItem := new(cache.QItem)
	qItem.AddrList = addresses
	qItem.JobId = job.JobId
	qItem.JobName = JobInfo.JobName
	qItem.JobFlType = JobInfo.FlSetting
	qItem.ExistingKey = JobInfo.ExistingKey
	qItem.PartyNums = JobInfo.PartyNum
	qItem.PartyInfo = pInfo
	qItem.Tasks = TaskInfo

	go func(){
		defer logger.HandleErrors()
		dist.SetupDist(qItem, common.InferenceWorker)
	}()

}


func QueryInference(job *common.InferenceJob, ctx *entity.Context) {

}


func StopInference(job *common.InferenceJob, ctx *entity.Context) {

}


func PublishInference(jobId uint, isTrained uint, ctx *entity.Context) {
	ctx.JobDB.Tx = ctx.JobDB.Db.Begin()

	e, _ := ctx.JobDB.PublishInference(jobId, isTrained)
	ctx.JobDB.Commit(e)
}


func InferenceUpdateStatus(jobId uint, status uint, ctx *entity.Context){
	ctx.JobDB.Tx = ctx.JobDB.Db.Begin()
	e, _ := ctx.JobDB.InferenceUpdateStatus(jobId, status)
	ctx.JobDB.Commit(e)

}