#!/bin/zsh

clear
ulimit -s unlimited;

ROOT=$(realpath "$1")
CPS_DEBUG="$2"
source "$CPS_PATH/project_config"

SF=$(($(date +%s%N)/1000000))
cd "$ROOT"

function compile() {
  FLAG=("${CPP_COMPILE_FLAG[@]}")
  USE_CACHE_LOCAL=$USE_CACHE
  if [ "$1" = "slow" ] || [ "$1" = "solution" ] || [ "$1" = "interactor" ]; then 
    if [ "$CPS_DEBUG" = "1" ]; then
      FLAG=("${CPP_DEBUG_FLAG[@]}")
      USE_CACHE_LOCAL="0"
    fi
  fi

  if [ $USE_CACHE_LOCAL = "1" ]; then
    mkdir -p "$CACHE_PATH" 
    if [ ! -f "$CACHE_PATH/$1.cpp" ] || [ $(cmp --silent "$ROOT/$1.cpp" "$CACHE_PATH/$1.cpp"; echo $?) -ne 0 ]; then # $1 in this case is a local variable
      g++ $FLAG -o "$1" "./$1.cpp"
      if [ $? -ne 0 ]; then
        echo -e "\e[31;1mCompile $1 file failed!\e[0m" 
        cleanup
        exit 0
      fi
      cp "$ROOT/$1.cpp" "$CACHE_PATH/$1.cpp"
      cp "$ROOT/$1" "$CACHE_PATH/$1"
    else
      cp "$CACHE_PATH/$1" "$ROOT/$1"
    fi
  else 
    g++ $FLAG -o "$1" "./$1.cpp"
    if [ $? -ne 0 ]; then
      echo -e "\e[31;1mCompile $1 file failed!\e[0m" 
      cleanup
      exit 0
    fi
  fi
}

if [ $USE_PRECOMPILED_HEADER = "1" ]; then
  CPP_COMPILE_FLAG+=("-include" "$PRECOMPILED_HEADER_PATH/stdc++.h") 
fi 

compile solution

cp "$ROOT/solution.cpp" "$OUTPUT_PATH"

./solution

rm -f ./solution

EF=$(($(date +%s%N)/1000000))
time=$((EF-SF))
echo
echo -e "\e[35;1mTesting finished in $time ms\e[0m"
