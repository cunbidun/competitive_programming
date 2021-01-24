#!/bin/zsh

clear
cd "$1"

prename=$(jq -r '.name' config.json)

java -jar ../../Script/Test.jar ./

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]
then
    FILE=./gen.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/gen.template ./gen.cpp
    fi  
fi

interactive=$(jq -r '.interactive' config.json)
if [ $interactive = "true" ]
then
    FILE=./interactor.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/interactor.template ./interactor.cpp
    fi  
fi


knowGenAns=$(jq -r '.knowGenAns' config.json)
if [ $knowGenAns = "true" ]
then
    FILE=./slow.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/slow.template ./slow.cpp
    fi  
fi

checker=$(jq -r '.checker' config.json)
if [ $checker = "custom" ]
then
    FILE=./checker.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/checker.template ./checker.cpp
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
