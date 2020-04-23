reset
clear

mkdir TestCase

g++ -DLOCAL -static -O2 -include ../Script/stdc++.h -o test ./test.cpp --std=c++17;

./test 
# > out.out

rm ./test