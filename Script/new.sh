cd $1

mkdir ___newTask

cd ___newTask

cp ../../Template/solution.template ./solution.cpp
cp ../../Template/config.template ./config.json

../../Script/config.sh "$1/___newTask/"

name=$(jq -r '.name' config.json)

cd ..
if [ "$name" = "" ]; then
    rm -rf ___newTask
else 
    mv ___newTask "$name"
fi