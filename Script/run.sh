#!/bin/zsh

clear

ROOT_DIR="$1"
DASH_SEPERATOR="\e[34;1m--------------------------------------------------------\e[0m"
EQUAL_SEPERATOR="========================================================"

compact=true

if $compact; then
    DASH_SEPERATOR="\e[34;1m---------------------------\e[0m"
    EQUAL_SEPERATOR="==========================="
fi

TESTING_START=$(($(date +%s%N)/1000000));
function cleanup() {
    cd "$ROOT_DIR"
    rm -rf ./TestCase 
    rm -f ./solution 
    rm -f ./checker 
    rm -f ./gen 
    rm -f ./interactor
}

trap '
    cleanup
    echo
    echo "\e[31;1mReceived SIGINT\e[0m"
    echo "$DASH_SEPERATOR"
    echo "$EQUAL_SEPERATOR"
    echo "Test results:" 
    TESTING_END=$(($(date +%s%N)/1000000)) 
    time=$((TESTING_END - TESTING_START)) 
    echo "\e[35;1mAll Testing finished in $time ms\e[0m"
    exit 0
' INT;

ulimit -s unlimited;

cleanup

cd "$1";

COMPILE_START=$(($(date +%s%N)/1000000))

if [ ! "$(<$1/solution.cpp)" = "$(<$1/../../Cache/solution.cpp)" ]; then 
    g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o solution ./solution.cpp --std=c++17
    if [ $? -ne 0 ]; then
        echo "\e[31;1mCompile solution file failed!\e[0m" 
        cleanup
        exit 0
    fi
        cp "$1/solution.cpp" "$1/../../Cache/solution.cpp"
        cp "$1/solution" "$1/../../Cache/solution"
else
    cp "$1/../../Cache/solution" "$1/solution"
fi

isInteractive=$(jq -r '.isInteractive' config.json)
if [ $isInteractive = "true" ]; then
    if [ ! "$(<$1/interactor.cpp)" = "$(<$1/../../Cache/interactor.cpp)" ]; then 
        g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o interactor ./interactor.cpp --std=c++17;
    if [ $? -ne 0 ]
        then
            echo "\e[31;1mCompile interactor file failed!\e[0m" 
            cleanup
            exit 0
        fi
        echo "\e[36;1mInteractive Task!\e[0m" 
        cp "$1/interactor.cpp" "$1/../../Cache/interactor.cpp"
        cp "$1/interactor" "$1/../../Cache/interactor"
    else
        echo "\e[36;1mInteractive Task!\e[0m" 
        cp "$1/../../Cache/interactor" "$1/interactor"
    fi
else
    checkerType=$(jq -r '.checker' config.json)
    if [ $checkerType != "custom" ]; then
        cp ../../Script/checkers/compiled/$checkerType ./checker
        echo "\e[36;1mUsing $checkerType checker!\e[0m" 
    else 
        if [ ! "$(<$1/checker.cpp)" = "$(<$1/../../Cache/checker.cpp)" ]; then 
            g++ -DLOCAL -static -O2 -include ../../Script/stdc++.h -o checker ./checker.cpp --std=c++17;
        if [ $? -ne 0 ]
            then
                echo "\e[31;1mCompile checker file failed!\e[0m" 
                cleanup
                exit 0
            fi
            echo "\e[36;1mUse Local Checker!\e[0m" 
            cp "$1/checker.cpp" "$1/../../Cache/checker.cpp"
            cp "$1/checker" "$1/../../Cache/checker"
        else
            echo "\e[36;1mUse Local Checker!\e[0m" 
            cp "$1/../../Cache/checker" "$1/checker"
        fi
    fi
fi

useGeneration=$(jq -r '.useGeneration' config.json)
if [ $useGeneration = "true" ]; then
    knowGenAns=$(jq -r '.knowGenAns' config.json)
    if [ $knowGenAns = "true" ]; then
        mkdir tmp
        cat ./gen.cpp > ./tmp/orig    
        awk 'NR>5' ./slow.cpp > ./tmp/tmp
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
                cleanup
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

if [ $compact = "false" ]; then
    echo "$(jq -r '.group' config.json)"
    echo "$(jq -r '.name' config.json)" 
    COMPILE_END=$(($(date +%s%N)/1000000))
    time=$((COMPILE_END-COMPILE_START))
    echo "\e[35;1mCompilations finished in $time ms\e[0m" 
fi

echo "$DASH_SEPERATOR"

timeLimit=$(jq -r '.timeLimit' config.json);
allPassed=true;
tle=false;
rte=false;
maxTime=0;

../../Script/testcases_parser/tc_parser $1$

#stress test
if [ $useGeneration = "true" ];
then 
    numTest=$(jq -r '.numTest' config.json) 
    genParameters=$(jq -r '.genParameters' config.json) 
    java -jar ../../Script/Gen.jar "$1" $numTest "$genParameters" 
fi


#test
truncateLongTest=$(jq -r '.truncateLongTest' config.json) 
stopAtWrongAnswer=$(jq -r '.stopAtWrongAnswer' config.json)

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
            printf "\e[33;1mTest #${f%.*}: \e[0m" 
        else 
            printf "\e[36;1mTest #${f%.*}: \e[0m" 
        fi

        START=$(($(date +%s%N)/1000000))
        ../solution < $f > "${f%.*}.actual"
        if [ $? -ne 0 ];then 
            rte=true 
            echo "Verdict: \e[31;1mrun time error\e[0m" 
            echo "$DASH_SEPERATOR"
            continue 
        fi 
        END=$(($(date +%s%N)/1000000)) 
        time=$((END - START)) 
        expected_output=false
        if test -f "${f%.*}.out"; then
            expected_output=true
        fi
        touch "${f%.*}.out"
        ../checker "$f" "${f%.*}.actual" "${f%.*}.out" "${f%.*}.res" > /dev/null 2>&1 
        read line < "${f%.*}.res" 
        passed=true;
        undecided=false
        for word in $line; do
            if [ "$word" = "wrong answer" ]; then 
                passed=false 
                allPassed=false 
            fi 
            if [ "$word" = "undecided" ]; then 
                undecided=true
            fi 
            break 
        done
        if [[ $compact = "true" ]] && [[ $passed = "true" ]] && [[ $timeLimit -ge $time ]] && [[ $undecided = "false" ]]; then
            echo "\e[32;1maccepted\e[0m" 
        else 
            echo  
            in=$(<$f) 
            echo "Input:" 
            if [ $truncateLongTest = "true" ] && [ ${#in} -gt 71 ]; then 
                echo "${in:0:35}...${in:$((${#in} - 35)):$((${#in} - 1))}" 
            else 
                echo $in 
            fi

            if $expected_output; then 
                echo "Expected output:" 
                out=$(<${f%.*}.out) 
                if [ $truncateLongTest = "true" ] && [ ${#out} -gt 71 ]; then
                    echo "${out:0:35}...${out:$((${#out} - 35)):$((${#out} - 1))}" 
                else 
                    echo $out 
                fi
            fi

            echo "Execution output:" 
            out=$(<${f%.*}.actual) 
            if [ $truncateLongTest = "true" ] && [ ${#out} -gt 71 ]; then 
                echo "${out:0:35}...${out:$((${#out} - 35)):$((${#out} - 1))}"
            else 
                echo $out 
            fi

            printf "Verdict: " 

            if $passed; then 
                if [ $timeLimit -ge $time ]; then 
                    if $undecided; then
                        export GREP_COLORS='ms=01;33' 
                        grep --color -E "undecided|$" "${f%.*}.res" 
                        passed=false 
                    else
                        export GREP_COLORS='ms=01;32' 
                        grep --color -E "accepted|$" "${f%.*}.res" 
                    fi
                else 
                    echo "\e[31;1mtime limit exceed\e[0m" 
                    passed=false 
                fi 
            else 
                export GREP_COLORS='ms=01;31' 
                grep --color -E "wrong answer|$" "${f%.*}.res" 
                if [ $stopAtWrongAnswer = "true" ]; then
                    cleanup
                    echo "$DASH_SEPERATOR"
                    echo "$EQUAL_SEPERATOR"
                    echo "Test results:" 
                    echo "\e[31;1mwrong answer detected!\e[0m"
                    TESTING_END=$(($(date +%s%N)/1000000)) 
                    time=$((TESTING_END - TESTING_START)) 
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
        fi

        if [ $time -gt $maxTime ]; then 
            maxTime=$time 
        fi 
        echo "$DASH_SEPERATOR"
    done 

    # generate testcase    
    # cd ..
    # ../../Script/convert.sh
    # cd './TestCase'
fi

cleanup

echo "$EQUAL_SEPERATOR"
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

TESTING_END=$(($(date +%s%N)/1000000)) 
time=$((TESTING_END - TESTING_START)) 
if [ $compact = "false" ]; then
  echo "\e[35;1mAll Testing finished in $time ms\e[0m"
fi
