package config

type QItem struct {
	IPs       []string
	JobId     uint
	PartyPath []PartyPath
	TaskInfos Tasks

	ModelPath []string
	ExecutablePath []string
}