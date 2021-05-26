#!/bin/zsh

clear
ulimit -s unlimited;

ROOT="$1"
source "$CPS_CONFIG_PATH"

SF=$(($(date +%s%N)/1000000))
cd "$ROOT"

function compile() {
  mkdir -p "$CACHE_PATH" 
  if [ ! -f "$CACHE_PATH/$1.cpp" ] || [ ! "$(<$ROOT/$1.cpp)" = "$(<$CACHE_PATH/$1.cpp)" ]; then # $1 in this case is a local variable
    if [ $USE_PRECOMPILED_HEADER = "1" ]; then
      g++ $CPP_COMPILE_FLAG -include "$PRECOMPILED_HEADER_PATH/stdc++.h" -o "$1" "./$1.cpp"
    else
      g++ $CPP_COMPILE_FLAG -o "$1" "./$1.cpp"
    fi
    if [ $? -ne 0 ]; then
      echo "\e[31;1mCompile $1 file failed!\e[0m" 
      cleanup
      exit 0
    fi
      cp "$ROOT/$1.cpp" "$CACHE_PATH/$1.cpp"
      cp "$ROOT/$1" "$CACHE_PATH/$1"
  else
    cp "$CACHE_PATH/$1" "$ROOT/$1"
  fi
}

compile solution

cp ./solution "$OUTPUT_PATH"

./solution

rm -f ./solution

EF=$(($(date +%s%N)/1000000))
time=$((EF-SF))
echo
echo "\e[35;1mTesting finished in $time ms\e[0m"
