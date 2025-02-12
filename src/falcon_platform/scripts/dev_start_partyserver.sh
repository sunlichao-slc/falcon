#!/bin/bash

# exit on error
set -e

if [ "$#" -ne 2 ]; then
    echo "Illegal number of parameters"
    echo "Usage: bash dev_start_partyserver.sh --partyID <PARTY_ID>"
    exit 1
fi

# from https://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    --partyID)
    PARTY_ID="$2"
    shift # past argument
    shift # past value
    ;;
    *)    # unknown option
    echo "No party ID provided"
    echo "Usage: bash dev_start_partyserver.sh --partyID <PARTY_ID>"
    exit 1
    shift # past argument
    ;;
esac
done

echo "PARTY_ID = ${PARTY_ID}"

# populate the environmental variables from
# the config_.properties files, such as paths IP and Ports
source config_partyserver.properties

# if Party server rpcbase path is not supplied in the config.properties
# then use falcon_logs/
if [ $PARTY_SERVER_BASEPATH ];then
	echo "PARTY_SERVER_BASEPATH provided: $PARTY_SERVER_BASEPATH"
	export PARTY_SERVER_BASEPATH=$PARTY_SERVER_BASEPATH
else
   # create new group of sub-folders with each run
   TIMESTAMP=$(date +%Y%m%d_%H%M%S)  # for hh:mm:ss
   DEV_TEST_OUTDIR=./falcon_logs/Party-${PARTY_ID}_${TIMESTAMP}

	 export PARTY_SERVER_BASEPATH=$DEV_TEST_OUTDIR
   echo "PARTY_SERVER_BASEPATH NOT provided, will use ${PARTY_SERVER_BASEPATH}"
fi

# setup party X folders
echo "creating folders for party-$PARTY_ID"

# set up the folder/sub-folders inside PARTY_SERVER_BASEPATH
# first create PARTY_SERVER_BASEPATH/ if not already exists
mkdir -p $PARTY_SERVER_BASEPATH

# TODO: later find a way to populate these subdirs
# based on {Coord, PartyServer}BasePath
# mkdir $DEV_TEST_OUTDIR/logs
# mkdir $DEV_TEST_OUTDIR/data_input
# mkdir $DEV_TEST_OUTDIR/data_output
# mkdir $DEV_TEST_OUTDIR/trained_models

export ENV="local"
export SERVICE_NAME="partyserver"
export COORD_SERVER_IP=$COORD_SERVER_IP
export COORD_SERVER_PORT=$COORD_SERVER_PORT
export PARTY_SERVER_IP=$PARTY_SERVER_IP
export LOG_PATH=$PARTY_SERVER_BASEPATH/falcon_logs

# increment coordinator server port by partyserver ID
# party ID can be 0, so needs to add extra 1
let port=$PARTY_ID+$COORD_SERVER_PORT+1
echo using $port for PARTY_SERVER_NODE_PORT
export PARTY_SERVER_NODE_PORT=$port
export PARTY_ID=$PARTY_ID

export MPC_EXE_PATH=$MPC_EXE_PATH
export FL_ENGINE_PATH=$FL_ENGINE_PATH

# launch party server X
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
make $makeOS

# NOTE: need "2>&1" before "&"
# To redirect both stdout and stderr to the same file
./bin/falcon_platform > $PARTY_SERVER_BASEPATH/Party-${PARTY_ID}-console.log 2>&1 &

# store the process id in basepath
echo $! > ./falcon_logs/Party-${PARTY_ID}.pid

echo "===== Done with Party-${PARTY_ID} ====="
echo
