#!/bin/zsh

rm -rf bits

x=$(g++ -DLOCAL -static -O2 --std=c++17 file.cpp -H 2>&1 | grep bits/stdc++.h)
directory=`echo $x | awk '{ print $NF }'`

if [ -f "$directory" ]; then
    echo "$directory exists."
else 
    echo "$directory does not exist."
fi

mkdir bits
cp $directory bits/
cd bits
g++ -DLOCAL -static -O2 --std=c++17 stdc++.h

mv stdc++.h.gch ../../

cd ..

rm -rf a.out
rm -rf bits