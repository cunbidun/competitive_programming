#!/bin/bash

x=$(g++ -DLOCAL -static -O2 --std=c++17 $1 -H 2>&1 | grep bits/stdc++.h)
directory=`echo $x | awk '{ print $NF }'`

mkdir bits
cp $directory bits/
cd bits
g++ -DLOCAL -static -O2 --std=c++17 stdc++.h
