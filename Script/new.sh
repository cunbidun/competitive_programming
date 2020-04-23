cd ../Task/

mkdir newTask

cd newTask

cp ../../Template/solution.template ./solution.cpp
cp ../../Template/config.template ./config.json

../../Script/config.sh

name=$(jq -r '.name' config.json)

cd ..
if [ "$name" = "" ]; then
    rm -rf newTask
else 
    mv newTask $name
fi