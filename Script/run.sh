#!/bin/zsh

clear
ulimit -s unlimited;

compact=false
ROOT="$1"
CACHE="$1/../../Cache/"
SCRIPT="$1/../../Script/"

DASH_SEPERATOR="\e[34;1m--------------------------------------------------------\e[0m"
EQUAL_SEPERATOR="========================================================"
GENERATOR_TOKEN=""


if $compact; then
    DASH_SEPERATOR="\e[34;1m---------------------------\e[0m"
    EQUAL_SEPERATOR="==========================="
fi

function cleanup() {
    cd "$ROOT"
    rm -rf TestCase solution checker gen slow
}

function compile() {
    mkdir -p "$CACHE"
    if [ ! -f "$CACHE/$1.cpp" ] || [ ! "$(<$ROOT/$1.cpp)" = "$(<$CACHE/$1.cpp)" ]; then 
        g++ -DLOCAL -static -O2 -include "$SCRIPT/stdc++.h" -o "$1" "./$1.cpp" --std=c++17
        if [ $? -ne 0 ]; then
            echo "\e[31;1mCompile $1 file failed!\e[0m" 
            cleanup
            exit 0
        fi
            cp "$ROOT/$1.cpp" "$CACHE/$1.cpp"
            cp "$ROOT/$1" "$CACHE/$1"
    else
        cp "$CACHE/$1" "$ROOT/$1"
    fi
}

cleanup

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

TESTING_START=$(($(date +%s%N)/1000000));

cd "$ROOT"

if [ $compact = "false" ]; then
    echo "$(jq -r '.group' config.json)"
    echo "$(jq -r '.name' config.json)" 
fi

checkerType=$(jq -r '.checker' config.json)
useGeneration=$(jq -r '.useGeneration' config.json)
knowGenAns=$(jq -r '.knowGenAns' config.json)
isInteractive=$(jq -r '.isInteractive' config.json)

# ----------------------------- COMPILE ----------------------------
COMPILE_START=$(($(date +%s%N)/1000000))

compile solution

if [ $checkerType != "custom" ]; then
    cp ../../Script/checkers/compiled/$checkerType ./checker
    echo "\e[36;1mUsing $checkerType checker!\e[0m" 
else 
    compile checker
    echo "\e[36;1mUse Local Checker!\e[0m" 
fi

if [ $useGeneration = "true" ]; then
    if [[ -z $GENERATOR_TOKEN ]]; then
        GENERATOR_TOKEN="$RANDOM$RANDOM"
    fi
    if [ $knowGenAns = "true" ]; then
        compile slow
    fi
    compile gen
    echo "\e[34;1mStress Test with token: '$GENERATOR_TOKEN'\e[0m" 
fi
# ----------------------------- COMPILE -----------------------------

if [ $compact = "false" ]; then
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

truncateLongTest=$(jq -r '.truncateLongTest' config.json) 
stopAtWrongAnswer=$(jq -r '.stopAtWrongAnswer' config.json)
numTest=$(jq -r '.numTest' config.json) 
cp ./solution.cpp ../../output

cd './TestCase/'

if [ $useGeneration = "true" ]; then
    ../gen "$GENERATOR_TOKEN" "$numTest" 
fi

#test
for f in `ls -v *.in` 
do
    if [ ${f:0:1} = "S" ]; then
        if [ $knowGenAns = "true" ]; then
            ../slow < $f > "${f%.*}.out" 
        fi
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
                else
                    export GREP_COLORS='ms=01;32' 
                    grep --color -E "accepted|$" "${f%.*}.res" 
                fi
            else 
                echo "\e[31;1mtime limit exceed\e[0m" 
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