#!/bin/zsh

clear

ROOT=$1:A
CPS_DEBUG="$2"
source "$CPS_PATH/project_config"

cd $ROOT

name=$(jq -r '.name' config.json)
group=$(jq -r '.group' config.json)

cd $TASK_PATH 

if [ "$group" = "" ]; then
    mv "$name" "$ARCHIVE_PATH/Unsorted/"
else
    mkdir -p  "$ARCHIVE_PATH/$group/"
    mv "$name" "$ARCHIVE_PATH/$group/"
fi
