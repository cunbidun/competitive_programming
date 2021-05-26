#!/bin/zsh

source "$CPS_CONFIG_PATH"

rm -rf bits

x=$(g++ $CPP_COMPILE_FLAG "$PRECOMPILED_HEADER_PATH/file.cpp" -H 2>&1 | grep bits/stdc++.h)
directory=`echo $x | awk 'END{ print $NF }'`

mkdir bits
cp "$directory" bits/
cd bits
g++ $CPP_COMPILE_FLAG stdc++.h

mv stdc++.h.gch "$PRECOMPILED_HEADER_PATH"

cd ..

rm -rf a.out
rm -rf bits
