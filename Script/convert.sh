#!/bin/zsh
p="CAU1"
dir="/mnt/c/Users/cunbidun/Documents/CVA/11-22-2020/homework/problems/"

mkdir $p 

cd TestCase
rm *.actual
rm *.res

cnt=0
for f in `ls -v *.in`
do
  if [ ${f:0:1} = "S" ]; then
    let "cnt+=1"
    mkdir "../$p/$cnt"
    cp $f "../$p/$cnt/$p.INP"
    cp ${f%.*}.out "../$p/$cnt/$p.OUT"
  fi
done

cd ..
cp -r "$p" "$dir"

rm -rf $p