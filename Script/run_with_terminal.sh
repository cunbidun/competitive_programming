#!/bin/zsh

clear

SF=$(($(date +%s%N)/1000000))

cd "$1"

if [ ! "$(<$1/solution.cpp)" = "$(<$1/../../Cache/solution.cpp)" ]; then 
    g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o solution ./solution.cpp --std=c++17
    if [ $? -ne 0 ]; then
        echo "\e[31;1mCompile solution file failed!\e[0m" 
        cleanup
        exit 0
    fi
        cp "$1/solution.cpp" "$1/../../Cache/solution.cpp"
        cp "$1/solution" "$1/../../Cache/solution"
else
    cp "$1/../../Cache/solution" "$1/solution"
fi

cp ./solution.cpp ../../output

./solution

rm -f ./solution

EF=$(($(date +%s%N)/1000000))
time=$((EF-SF))
echo "\e[35;1mTesting finished in $time ms\e[0m"
