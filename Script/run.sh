#!/bin/zsh
#reset

SF=$(($(date +%s%N)/1000000));
START=$(($(date +%s%N)/1000000));

trap ' 
    rm -rf ../TestCase 
    rm -rf ../solution 
    rm -f ../checker 
    rm -f ../gen 
    echo
    echo "\e[31;1mReceived SIGINT\e[0m"
    echo "--------------------------------------------------------"
    echo "========================================================"
    echo "Test results:" 
    EF=$(($(date +%s%N)/1000000)) 
    time=$((EF - SF)) 
    echo "\e[35;1mAll Testing finished in $time ms\e[0m"

    exit 0
' INT;
clear;

ulimit -s unlimited;

cd "$1";

contest=$(jq -r '.group' config.json)
problem=$(jq -r '.name' config.json)
echo "$contest"
echo "$problem" 

if [ ! "$(<$1/solution.cpp)" = "$(<$1/../../Cache/solution.cpp)" ]; then 
    g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o solution ./solution.cpp --std=c++17
    if [ $? -ne 0 ]; then
        echo "\e[31;1mCompile solution file failed!\e[0m" 
        rm -rf ./TestCase 
        rm -f ./solution 
        rm -f ./checker 
        rm -f ./gen  
        exit 0
    fi
        cp "$1/solution.cpp" "$1/../../Cache/solution.cpp"
        cp "$1/solution" "$1/../../Cache/solution"
else
    cp "$1/../../Cache/solution" "$1/solution"
fi

useLocalChecker=$(jq -r '.useLocalChecker' config.json)
if [ $useLocalChecker = "false" ]; then
    cp ../../Script/checker ./
    echo "\e[34;1mUse Global Checker!\e[0m" 
else 
    if [ ! "$(<$1/checker.cpp)" = "$(<$1/../../Cache/checker.cpp)" ]; then 
        g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o checker ./checker.cpp --std=c++17;
    if [ $? -ne 0 ]
        then
            echo "\e[31;1mCompile checker file failed!\e[0m" 
            rm -rf ./TestCase 
            rm -f ./solution 
            rm -f ./checker 
            rm -f ./gen  
            exit 0
        fi
        echo "\e[34;1mUse Local Checker!\e[0m" 
        cp "$1/checker.cpp" "$1/../../Cache/checker.cpp"
        cp "$1/checker" "$1/../../Cache/checker"
    else
        echo "\e[34;1mUse Local Checker!\e[0m" 
        cp "$1/../../Cache/checker" "$1/checker"
    fi
fi

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]; then
    numTest=$(jq -r '.numTest' config.json) 
    genParameters=$(jq -r '.genParameters' config.json) 
    knowGenAns=$(jq -r '.knowGenAns' config.json)

    if [ $knowGenAns = "true" ]; then
        mkdir tmp
        cat ./gen.cpp > ./tmp/orig    
        awk 'NR>12' ./slow.cpp > ./tmp/tmp
        sed -i 's/ cin / in /g' ./tmp/tmp
        sed -i 's/ cout / out /g' ./tmp/tmp
        sed -i 's/main/___solve/g' ./tmp/tmp
        sed -i 's/___solve(){}/___solve()/g' ./gen.cpp 
        cat ./tmp/tmp >> ./gen.cpp   
    fi
    if [ ! "$(<$1/gen.cpp)" = "$(<$1/../../Cache/gen.cpp)" ]; then 
        g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o gen ./gen.cpp --std=c++17;
        if [ $? -ne 0 ]
            then
                echo "\e[31;1mCompile generator file failed!\e[0m" 
                rm -rf ./TestCase 
                rm -f ./solution 
                rm -f ./checker 
                rm -f ./gen  
                if [ $knowGenAns = "true" ]; then
                    cp ./tmp/orig ./gen.cpp
                    rm -rf tmp 
                fi
                exit 0
            fi
        echo "\e[34;1mStress Test!\e[0m" 
        cp "$1/gen.cpp" "$1/../../Cache/gen.cpp"
        cp "$1/gen" "$1/../../Cache/gen"
    else 
        echo "\e[34;1mStress Test!\e[0m" 
        cp "$1/../../Cache/gen" "$1/gen"
    fi
    if [ $knowGenAns = "true" ]; then
        cp ./tmp/orig ./gen.cpp
        rm -rf tmp 
    fi
fi

END=$(($(date +%s%N)/1000000))
time=$((END-START))
echo "\e[35;1mCompilations finished in $time ms\e[0m" 
echo '--------------------------------------------------------' 

timeLimit=$(jq -r '.timeLimit' config.json);
allPassed=true;
tle=false;
rte=false;
maxTime=0;

java -jar ../../Script/ToTestText.jar "$1";

#stress test
if [ $useGeneration = "true" ];
then 
    java -jar ../../Script/Gen.jar "$1" $numTest "$genParameters" 
fi


#test
truncateLongTest=$(jq -r '.truncateLongTest' config.json) 
checkerParameters=$(jq -r '.checkerParameters' config.json)
printWrongAnswer=$(jq -r '.printWrongAnswer' config.json)

DIR="./TestCase/" 
if [ "$(ls -A $DIR)" ]; then
    cd './TestCase/'

    cp ../solution.cpp ../../../output
    for f in `ls -v *.in` 
    do
        if [ ! -f $f ]; then 
            continue;
        fi

        if [ ${f:0:1} = "S" ]; then
            ../gen "$f" "$knowGenAns" 
            echo "\e[33;1mTest #${f%.*}:\e[0m" 
        else 
            echo "\e[36;1mTest #${f%.*}:\e[0m" 
        fi

        in=$(<$f) 
        echo "Input:" 
        if [ $truncateLongTest = "true" ] && [ ${#in} -gt 71 ]; then 
            echo "${in:0:35}...${in:$((${#in} - 35)):$((${#in} - 1))}" 
        else 
            echo $in 
        fi

        if test -f "${f%.*}.out"; then 
            echo "Expected output:" 
            out=$(<${f%.*}.out) 
            if [ $truncateLongTest = "true" ] && [ ${#out} -gt 71 ]; then
                echo "${out:0:35}...${out:$((${#out} - 35)):$((${#out} - 1))}" 
            else 
                echo $out 
            fi
        fi
        echo "Execution output:" 
        START=$(($(date +%s%N)/1000000))
        ../solution < $f > "${f%.*}.actual"
        if [ $? -ne 0 ];then 
            rte=true 
            echo "Verdict: \e[31;1mRTE\e[0m" 
            echo '--------------------------------------------------------' 
            continue 
        fi 
        END=$(($(date +%s%N)/1000000)) 
        time=$((END - START)) 
        out=$(<${f%.*}.actual) 
        if [ $truncateLongTest = "true" ] && [ ${#out} -gt 71 ]; then 
            echo "${out:0:35}...${out:$((${#out} - 35)):$((${#out} - 1))}"
        else 
            echo $out 
        fi

        if [ "$checkerParameters" = "" ]; then 
            if test -f "${f%.*}.out"; then
                ../checker "$f" "${f%.*}.out" "${f%.*}.actual" > "${f%.*}.res" 
            else
                ../checker "$f" "" "${f%.*}.actual" > "${f%.*}.res" 
            fi 
        else 
            if test -f "${f%.*}.out"; then
                ../checker "$f" "${f%.*}.out" "${f%.*}.actual" "$checkerParameters" > "${f%.*}.res" 
            else 
                ../checker "$f" "" "${f%.*}.actual" "$checkerParameters" > "${f%.*}.res" 
            fi 
        fi

        read line < "${f%.*}.res" 
        passed=true;
        for word in $line; do
            if [ "$word" = "WA" ]; then 
                passed=false 
                allPassed=false 
            fi 
                break 
        done

        printf "Verdict: " 
        if $passed; then 
            if [ $timeLimit -ge $time ]; then 
                export GREP_COLORS='ms=01;32' 
                grep --color -E "OK|$" "${f%.*}.res" 
            else 
                echo "\e[31;1mTLE\e[0m" 
            fi 
        else 
            export GREP_COLORS='ms=01;31' 
            grep --color -E "WA|$" "${f%.*}.res" 
            if [ $printWrongAnswer = "true" ]; then
                rm -rf ../TestCase 
                rm -rf ../solution 
                rm -f ../checker 
                rm -f ../gen 
                echo "--------------------------------------------------------"
                echo "========================================================"
                echo "Test results:" 
                echo "\e[31;1mWA Detected!\e[0m"
                EF=$(($(date +%s%N)/1000000)) 
                time=$((EF - SF)) 
                echo "\e[35;1mAll Testing finished in $time ms\e[0m"
                exit 0
            fi
        fi

        printf "Run Time: " 
        if [ $time -gt $timeLimit ]; then 
            tle=true 
            echo "\e[31;1m$time\e[0m ms" 
        else 
            echo "\e[32;1m$time\e[0m ms" 
        fi

        if [ $time -gt $maxTime ]; then 
            maxTime=$time 
        fi 
        echo '--------------------------------------------------------' 
    done 
    rm -rf ../TestCase 
    rm -f ../solution 
    rm -f ../checker 
    rm -f ../gen 
else 
    cd './TestCase/'
    rm -rf ../TestCase 
    rm -f ../solution 
    rm -f ../checker 
    rm -f ../gen  
fi

echo '========================================================' 
echo "Test results:"

if $rte; then 
    echo "\e[31;1mRun Time Error!\e[0m" 
else 
    if $allPassed; then 
        if $tle; then 
            echo "\e[31;1mTime limit exceeded!\e[0m" 
        else 
            printf "\e[32;1mAll test passed!\e[0m" 
            echo " in \e[32;1m$maxTime\e[0m ms." 
        fi 
    else 
        echo "\e[31;1mSome cases failed!\e[0m" 
    fi 
fi

EF=$(($(date +%s%N)/1000000)) 
time=$((EF - SF)) 
echo "\e[35;1mAll Testing finished in $time ms\e[0m"