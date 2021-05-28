#!/bin/bash

source "$CPS_PATH/project_config"

mkdir -p "$TASK_PATH" # create directory if not exist
cd "$TASK_PATH"

mkdir -p ___newTask

cd ___newTask

cp "$TEMPLATE_PATH/solution.template" ./solution.cpp
cp "$TEMPLATE_PATH/config.template" ./config.json

"$SCRIPT_PATH/config.sh" "$TASK_PATH/___newTask/"

name=$(jq -r '.name' config.json)

cd ..
if [ "$name" = "" ]; then
	rm -rf ___newTask
else
	mv ___newTask "$name"
fi
