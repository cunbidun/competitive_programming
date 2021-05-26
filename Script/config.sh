#!/bin/zsh

clear

ROOT="$1"
source "$CPS_CONFIG_PATH"

cd "$ROOT" 

prename=$(jq -r '.name' config.json)

java -jar "$FRONTEND_PATH" "$ROOT/" 

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]
then
  FILE=./gen.cpp
  if [ ! -f "$FILE" ]; 
  then
    cp "$TEMPLATE_PATH/gen.template" ./gen.cpp
  fi  
fi

interactive=$(jq -r '.interactive' config.json)
if [ $interactive = "true" ]
then
  FILE=./interactor.cpp
  if [ ! -f "$FILE" ]; 
  then
    cp "$TEMPLATE_PATH/interactor.template" ./interactor.cpp
  fi  
fi


knowGenAns=$(jq -r '.knowGenAns' config.json)
if [ $knowGenAns = "true" ]
then
  FILE=./slow.cpp
  if [ ! -f "$FILE" ]; 
  then
    cp "$TEMPLATE_PATH/slow.template" ./slow.cpp
  fi  
fi

checker=$(jq -r '.checker' config.json)
if [ $checker = "custom" ]
then
  FILE=./checker.cpp
  if [ ! -f "$FILE" ]; 
  then
    cp "$TEMPLATE_PATH/checker.template" ./checker.cpp
  fi  
fi

name=$(jq -r '.name' config.json)

jq . config.json > tmp && mv tmp config.json

cd ..
if [ ! "$prename" = "" ]; then
  if [ ! "$name" = "$prename" ];then
    mv "$prename" "$name"
  fi
fi
