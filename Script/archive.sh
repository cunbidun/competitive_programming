clear
cd "$1"
name=$(jq -r '.name' config.json)
group=$(jq -r '.group' config.json)

cd ..

if [ "$group" = "" ]; then
    mv "$name" ../Archive/Unsorted/
else
    mkdir -p  ../Archive/"$group"/
    mv "$name" ../Archive/"$group"/
fi
