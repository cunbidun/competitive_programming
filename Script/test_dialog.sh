clear
cd "$1"

../../Script/Test.jar ./

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]
then
    FILE=./gen.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/gen.template ./gen.cpp
    fi  
fi
