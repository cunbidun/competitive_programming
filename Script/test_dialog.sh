clear
cd "$1"

java -jar ../../Script/Test.jar ./

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]
then
    FILE=./gen.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/gen.template ./gen.cpp
    fi  
fi

knowGenAns=$(jq -r '.knowGenAns' config.json)
if [ $knowGenAns = "true" ]
then
    FILE=./slow.cpp
    if [ ! -f "$FILE" ]; 
    then
        cp ../../Template/slow.template ./slow.cpp
    fi  
fi
