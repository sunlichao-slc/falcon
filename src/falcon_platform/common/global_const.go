package common

import (
	"falcon_platform/logger"
	"os"
)

// Master and Worker type name
const (
	Master          = "Master"
	TrainWorker     = "TrainWorker"
	InferenceWorker = "InferenceWorker"
)

// master and worker heartbeat timeout
const (
	// master& worker heartbeat
	MasterTimeout = 10000 //  send heartbeat every 10 second
	WorkerTimeout = 20000 //  receive heartbeat within every 20 second
)

// Rest Content type
const (
	JsonContentType      = "application/json"
	MultipartContentType = "multipart/form-data"
)

// Api route path
const (
	// router path for coordServer
	SubmitTrainJob         = "/api/submit-train-job"
	StopTrainJob           = "/api/stop-train-job"
	UpdateTrainJobMaster   = "/api/update-train-master"
	UpdateJobResInfo       = "/api/update-job-res"
	UpdateJobStatus        = "/api/update-job-status"
	QueryTrainJobStatus    = "/api/query-train-job-status"
	RetrieveTrainJobReport = "/api/get-evaluation-report-by-train-job-id"

	UpdateInferenceJobMaster = "/api/update-inference-master"
	InferenceStatusUpdate    = "/api/update-prediction-service-status"
	InferenceUpdate          = "/api/prediction-service-update"
	InferenceCreate          = "/api/prediction-service-create"
	ModelUpdate              = "/api/model-update"

	AssignPort         = "/api/port-assign"
	AddPort            = "/api/portadd"
	GetPartyServerPort = "/api/port-get"

	PartyServerAdd    = "/api/party-server-add"
	PartyServerDelete = "/api/party-server-del"

	// router path for partyserver
	RunWorker = "/api/setup-worker"
)

// key of dataBody  in rest
const (
	// shared key of map
	PartyServerAddrKey = "psAddr"
	MasterAddrKey      = "masterAddr"
	PartyServerPortKey = "psPort"
	JobId              = "job_id"
	JobErrMsg          = "error_msg"
	JobResult          = "job_result"
	JobExtInfo         = "ext_info"

	JobStatus = "status"

	TrainJobFileKey = "train-job-file"

	TaskTypeKey = "tasks-type"

	TrainDataPath          = "train-data-path"
	TrainDataOutput        = "train-data-output"
	ModelPath              = "model-path"
	WorkerPreParty         = "worker-num-pre-party"
	IsTrained              = "is_trained"
	TotalPartyNumber       = "total-party-num"
	EnableDistributedTrain = "enable-distributed-train"
	StageClassIDKey        = "stage-classId"
	JobTypeKey             = "job-type-key"

	JobName = "job_name"
	ExtInfo = "ext_info"

	Network = "tcp"
)

// is debug or not, if debug, the worker will execute test methods
// deploy-docker.go will use test image
const (
	DebugOn = "debug-on"
)

// deployment methods
const (
	// for common.Deployment, which is control running in production or dev
	LocalThread = "subprocess"
	Docker      = "docker"
	K8S         = "k8s"
)

// Path of config, logs or scripts
const (
	// config file path
	WorkerYamlCreatePath = "./scripts/_create_runtime_worker.sh"
	MasterYamlCreatePath = "./scripts/_create_runtime_master.sh"
	YamlBasePath         = "./deploy/template/"

	// RuntimeLogs folder name
	RuntimeLogs = "runtime_logs"

	// Path in containers
	DataPathContainer       = "/dataPath"
	DataOutputPathContainer = "/dataOutputPath"
	ModelPathContainer      = "/modelPath"
)

// Job or tasks status,
const (
	// job status
	JobInit    = "initializing"
	JobRunning = "running"
	// those 3 are job result
	JobSuccessful = "finished"
	JobFailed     = "failed"
	JobKilled     = "killed"

	// one job contains multi tasks, this is tasks status
	TaskRunning    = "tasks-running"
	TaskSuccessful = "tasks-finished"
	TaskFailed     = "tasks-failed"

	// for DB engine names
	DBSqlite3 = "sqlite3"
	DBMySQL   = "mysql"

	ActiveParty  = "active"
	PassiveParty = "passive"
)

type FalconTask string

// train sub tasks names
const (
	MpcTaskKey                 FalconTask = "mpc"
	PreProcTaskKey             FalconTask = "pre_processing"
	ModelTrainTaskKey          FalconTask = "model_training"
	LimeInstanceSampleTask     FalconTask = "lime_sampling"
	LimePredTaskKey            FalconTask = "lime_pred_task"
	LimeWeightTaskKey          FalconTask = "lime_weight_task"
	LimeFeatureTaskKey         FalconTask = "lime_feature_task"
	LimeInterpretTaskKey       FalconTask = "lime_interpret_task"
	RetrieveModelReportTaskKey FalconTask = "model_report_retrieve"
)

// Algorithms names
const (
	HorizontalFl = "horizontal"
	VerticalFl   = "vertical"

	PearsonAlgName = "lime"

	LogisticRegressAlgName  = "logistic_regression"
	DecisionTreeAlgName     = "decision_tree"
	RandomForestAlgName     = "random_forest"
	LinearRegressionAlgName = "linear_regression"
	GBDTAlgName             = "gbdt"
	MLPAlgName              = "mlp"

	LimeSamplingAlgName       = "lime_sampling"
	LimeCompPredictionAlgName = "lime_compute_prediction"
	LimeCompWeightsAlgName    = "lime_compute_weights"
	LimeFeatSelAlgName        = "lime_feature_selection"
	LimeInterpretAlgName      = "lime_interpret"

	LimeDecisionTreeAlgName     = "vfl_decision_tree"
	LimeLinearRegressionAlgName = "linear_regression"
)

// Ports used on mpc-executor communication, which is hardcoded in executor now
const (
	MpcExecutorPortFilePrefix = "Programs/Public-Input/"

	MpcExecutorBasePort = 44000
)

// Distributed role
const (
	DistributedParameterServer = 0
	DistributedWorker          = 1
	CentralizedWorker          = 2
)

// if pass empty params in cmd. pass "0" to avoid error
const (
	EmptyParams = "0"
)

// the service names, used to run different role
const (
	CoordinatorRole               = "coord"
	PartyServerRole               = "partyserver"
	JobManagerMasterRole          = "job-manager-master"
	JobManagerTrainWorkerRole     = "job-manager-train-worker"
	JobManagerInferenceWorkerRole = "job-manager-inference-worker"
)

func DistributedRoleToName(role uint) string {
	if role == 0 {
		return "dist-ps"
	} else if role == 1 {
		return "dist-worker"
	} else if role == 2 {
		return "cent-worker"
	} else {
		return ""
	}
}

// GetEnv get key environment variable if exist otherwise return defalutValue
func GetEnv(key, defaultValue string) string {
	value := os.Getenv(key)
	if len(value) == 0 {
		logger.Log.Printf("Set env var to default {%s: %s}\n", key, defaultValue)
		return defaultValue
	}
	logger.Log.Printf("Read user defined env var {%s: %s}\n", key, value)
	return value
}
