#!/bin/zsh

g++ -DLOCAL -static -O2 -o $1 "./source/$1.cpp" --std=c++17
mv $1 "./compiled/$1"