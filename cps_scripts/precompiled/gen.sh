#!/bin/bash

source "$CPS_PATH/project_config"

cd "$PRECOMPILED_HEADER_PATH" || exit

rm -rf bits
rm -rf debug

x=$(g++ "${CPP_COMPILE_FLAG[@]}" "$PRECOMPILED_HEADER_PATH/file.cpp" -H 2>&1 | grep bits/stdc++.h)
directory=$(echo "$x" | awk 'END{ print $NF }')

mkdir bits
mkdir debug

cp "$directory" bits/
cp "$directory" debug/

cd bits || exit
g++ "${CPP_COMPILE_FLAG[@]}" stdc++.h
mv stdc++.h.gch "$PRECOMPILED_HEADER_PATH"
cd "$PRECOMPILED_HEADER_PATH" || exit

cd debug || exit
g++ "${CPP_DEBUG_FLAG[@]}" stdc++.h
rm -rf stdc++.h
cd "$PRECOMPILED_HEADER_PATH" || exit

rm -rf a.out
rm -rf bits
