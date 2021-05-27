#!/bin/zsh

source "$CPS_CONFIG_PATH"

cd $PRECOMPILED_HEADER_PATH

rm -rf bits
rm -rf debug 

x=$(g++ $CPP_COMPILE_FLAG "$PRECOMPILED_HEADER_PATH/file.cpp" -H 2>&1 | grep bits/stdc++.h)
directory=`echo $x | awk 'END{ print $NF }'`

mkdir bits
mkdir debug

cp "$directory" bits/
cp "$directory" debug/

cd bits
g++ $CPP_COMPILE_FLAG stdc++.h
mv stdc++.h.gch "$PRECOMPILED_HEADER_PATH"
cd "$PRECOMPILED_HEADER_PATH"

cd debug 
g++ $CPP_DEBUG_FLAG stdc++.h
rm -rf stdc++.h
cd "$PRECOMPILED_HEADER_PATH"

rm -rf a.out
rm -rf bits

