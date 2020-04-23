clear
cd "$1"

prename=$(jq -r '.name' config.json)

../../Script/TaskConfigDialog.jar ./

useLocalChecker=$(jq -r '.useLocalChecker' config.json)
if [ $useLocalChecker = "true" ]
then
    FILE=./checker.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/checker.template ./checker.cpp
    fi  
fi

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]
then
    FILE=./gen.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/gen.template ./gen.cpp
    fi  
fi

name=$(jq -r '.name' config.json)

cd ..
if [ "$name" = "" ]; then
    rm -rf $prename
elif [ ! "$name" = "$prename" ];then
    mv $prename $name
fi