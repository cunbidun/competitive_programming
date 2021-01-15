#!/bin/zsh

clear

SF=$(($(date +%s%N)/1000000))

cd "$1"

g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o solution ./solution.cpp --std=c++17 && ./solution

rm -f ./solution

EF=$(($(date +%s%N)/1000000))
time=$((EF-SF))
echo "\e[35;1mTesting finished in $time ms\e[0m"