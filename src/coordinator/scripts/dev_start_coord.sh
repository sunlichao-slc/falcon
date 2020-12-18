#!/bin/bash

. config_coord.properties

# detect the OS type with uname
makeOS=''
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
   makeOS='build_linux'
elif [[ "$unamestr" == 'Darwin' ]]; then
   makeOS='build_mac'
elif [[ "$unamestr" == 'WindowsNT' ]]; then
   makeOS='build_windows'
fi

export Env=dev
export SERVICE_NAME=coord
export COORD_SERVER_IP=$COORD_SERVER_IP
export DATA_BASE_PATH=$DATA_BASE_PATH
export JOB_DB_ENGINE=$JOB_DB_ENGINE

make $makeOS
./bin/falcon_platform
