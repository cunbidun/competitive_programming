#!/bin/zsh
clear
ulimit -s unlimited

ROOT=$(realpath "$1")
CPS_DEBUG="$2"
source "$CPS_PATH/project_config"

DASH_SEPERATOR="\e[34;1m--------------------------------------------------------\e[0m"
EQUAL_SEPERATOR="========================================================"
cd "$ROOT" || exit

compact=$(jq -r '.compact' config.json) # compact mode
hideAcceptedTest=$(jq -r '.hideAcceptedTest' config.json)
generator_seed=$(jq -r '.generatorSeed' config.json)
truncateLongTest=$(jq -r '.truncateLongTest' config.json)

if $compact; then
	DASH_SEPERATOR="\e[1;34m---------------------------\e[0m"
	EQUAL_SEPERATOR="==========================="
fi

function cleanup() {
	cd "$ROOT" || exit
	rm -rf TestCase solution checker gen slow printer interactor
}

function p() {
	if [ "$truncateLongTest" = "true" ] && [ ${#1} -gt 71 ]; then
		printf "${1:0:35}...${1:$((${#1} - 35)):$((${#1} - 1))}\n"
	else
		printf "$1\n"
	fi
}

function compile() {
	FLAG=("${CPP_COMPILE_FLAG[@]}")
	USE_CACHE_LOCAL=$USE_CACHE
	if [ "$1" = "slow" ] || [ "$1" = "solution" ] || [ "$1" = "interactor" ]; then
		if [ "$CPS_DEBUG" = "1" ]; then
			FLAG=("${CPP_DEBUG_FLAG[@]}")
			USE_CACHE_LOCAL="0" # disable cache when run with CPS_DEBUG in solution and slow file
		fi
	fi

	if [ $USE_CACHE_LOCAL = "1" ]; then
		mkdir -p "$CACHE_PATH"
		if [ ! -f "$CACHE_PATH/$1.cpp" ] || [ "$(
			cmp --silent "$ROOT/$1.cpp" "$CACHE_PATH/$1.cpp"
			echo $?
		)" -ne 0 ]; then # $1 in this case is a local variable
			g++ "${FLAG[@]}" -o "$1" "./$1.cpp"
			if [ $? -ne 0 ]; then
				echo -e "\e[31;1mCompile $1 file failed!\e[0m"
				cleanup
				exit 0
			fi
			cp "$ROOT/$1.cpp" "$CACHE_PATH/$1.cpp"
			cp "$ROOT/$1" "$CACHE_PATH/$1"
		else
			cp "$CACHE_PATH/$1" "$ROOT/$1"
		fi
	else
		g++ "${FLAG[@]}" -o "$1" "./$1.cpp"
		if [ $? -ne 0 ]; then
			echo -e "\e[31;1mCompile $1 file failed!\e[0m"
			cleanup
			exit 0
		fi
	fi
}

cleanup

trap '
  cleanup
  echo
  echo -e "\e[31;1mReceived SIGINT\e[0m"
  echo -e "$DASH_SEPERATOR"
  echo "$EQUAL_SEPERATOR"
  echo "Test results:"
  TESTING_END=$(($(date +%s%N)/1000000))
  time=$((TESTING_END - TESTING_START))
  echo -e "\e[35;1mAll Testing finished in $time ms\e[0m"
  exit 0
' INT

TESTING_START=$(($(date +%s%N) / 1000000))

if [ "$compact" = "false" ]; then
	echo "$(jq -r '.group' config.json)"
	echo "$(jq -r '.name' config.json)"
fi

checkerType=$(jq -r '.checker' config.json)
useGeneration=$(jq -r '.useGeneration' config.json)
knowGenAns=$(jq -r '.knowGenAns' config.json)
interactive=$(jq -r '.interactive' config.json)

# ----------------------------- COMPILE ----------------------------
COMPILE_START=$(($(date +%s%N) / 1000000))

if [ "$USE_PRECOMPILED_HEADER" = "1" ]; then
	CPP_COMPILE_FLAG+=("-include" "$PRECOMPILED_HEADER_PATH/stdc++.h")
	CPP_DEBUG_FLAG+=("-include" "$PRECOMPILED_HEADER_PATH/debug/stdc++.h")
fi

compile solution

if [ "$interactive" = "true" ]; then
	compile interactor
	cp "$SCRIPT_PATH/interactive_printer/printer" ./printer
	echo -e "\e[36;1mInteractive Task!\e[0m"
else
	if [ "$checkerType" != "custom" ]; then
		cp "$SCRIPT_PATH/checkers/compiled/$checkerType" ./checker
		echo -e "\e[36;1mUsing $checkerType checker!\e[0m"
	else
		compile checker
		echo -e "\e[36;1mUse Local Checker!\e[0m"
	fi
fi

if [ $knowGenAns = "true" ]; then
	compile slow
fi

if [ $useGeneration = "true" ]; then
	if [[ -z $generator_seed ]]; then
		generator_seed="$RANDOM$RANDOM"
	fi
	compile gen
	echo -e "\e[34;1mStress Test with token: '$generator_seed'\e[0m"
fi

# ----------------------------- COMPILE -----------------------------

if [ $compact = "false" ]; then
	COMPILE_END=$(($(date +%s%N) / 1000000))
	time=$((COMPILE_END - COMPILE_START))
	echo -e "\e[35;1mCompilations finished in $time ms\e[0m"
fi

echo -e "$DASH_SEPERATOR"

timeLimit=$(jq -r '.timeLimit' config.json)
allPassed=true
tle=false
rte=false
maxTime=0

$SCRIPT_PATH/testcases_parser/tc_parser $1$

stopAtWrongAnswer=$(jq -r '.stopAtWrongAnswer' config.json)
numTest=$(jq -r '.numTest' config.json)
cp ./solution.cpp "$OUTPUT_PATH"

cd './TestCase/' || exit
if [ $useGeneration = "true" ]; then
	../gen "$generator_seed" "$numTest"
	if [ $? -ne 0 ]; then
		rte=true
		echo -e "\e[31;1mGenerator run time error!\e[0m"
		cleanup
		exit 0
	fi
fi

cd ..
DIR="./TestCase/"
if [ "$(ls -A $DIR)" ]; then
	if [ "$interactive" = "true" ]; then # because for execl in the interactor
		mv solution './TestCase'
	fi
	cd './TestCase/' || exit
	for f in $(ls -v *.in); do

		# print test num based on test type
		if [ ${f:0:1} = "S" ]; then
			printf "\e[33;1mTest #${f%.*}: \e[0m"
		else
			printf "\e[36;1mTest #${f%.*}: \e[0m"
		fi

		# if there is brute force solution, run it
		if [[ $interactive == "false" ]] && [[ $knowGenAns == "true" ]]; then
			../slow <$f >"${f%.*}.out"
			if [ $? -ne 0 ]; then
				echo -e "\e[31;1mSlow solution run time error!\e[0m"
				cleanup
				exit 0
			fi
		fi

		expected_output=false # variable to check if the ouput file is empty or not

		passed=true
		# if this is interactive task
		if [ "$interactive" = "true" ]; then
			START=$(($(date +%s%N) / 1000000))
			../interactor "$f" "${f%.*}.actual" "${f%.*}.res"
      exit_code=$?
			if [ $exit_code -ne 0 ] && [ $exit_code -ne 141 ]; then
				rte=true
				echo -e "Verdict: \e[31;1mrun time error\e[0m"
				echo -e "$DASH_SEPERATOR"
				continue
			fi
      if [ $exit_code = 141 ]; then
        echo "wrong answer" > "${f%.*}.res"
      fi
			END=$(($(date +%s%N) / 1000000))
			time=$((END - START))
		else                   # not interactive task
			START=$(($(date +%s%N) / 1000000))
			../solution <$f >"${f%.*}.actual"
			if [ $? -ne 0 ]; then # if there is run time error
				rte=true
				echo "Input:" # print the input when rte happen
				p "$(<$f)"
				echo -e "Verdict: \e[31;1mrun time error\e[0m"
				echo -e "$DASH_SEPERATOR"
				continue
			fi
			END=$(($(date +%s%N) / 1000000))
			time=$((END - START))
			if test -f "${f%.*}.out"; then
				expected_output=true
			fi
			touch "${f%.*}.out"
			../checker "$f" "${f%.*}.actual" "${f%.*}.out" "${f%.*}.res" >/dev/null 2>&1
		fi
		word=$(cat "${f%.*}.res" | head -n1 | awk '{print $1;}')
		undecided=false
		if [ "$word" = "wrong" ]; then
			passed=false
			allPassed=false
		fi
		if [ "$word" = "undecided" ]; then
			undecided=true
		fi
		if [[ $hideAcceptedTest == "true" ]] && [[ $passed == "true" ]] && [[ $timeLimit -ge $time ]] && [[ $undecided == "false" ]]; then
			export GREP_COLORS='ms=01;32'
			grep --color -E "accepted|$" "${f%.*}.res"
		else
			echo
			echo "Input:"
			p "$(<$f)"
			if $expected_output; then
				echo "Expected output:"
				p "$(<${f%.*}.out)"
			fi
			echo "Execution output:"
			if [ "$interactive" = "true" ]; then
				../printer "${f%.*}.actual"
			else
				p "$(<${f%.*}.actual)"
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
					echo -e "\e[31;1mtime limit exceed\e[0m"
				fi
			else
				export GREP_COLORS='ms=01;31'
				grep --color -E "wrong answer|$" "${f%.*}.res"
				if [ "$stopAtWrongAnswer" = "true" ]; then
					cleanup
					echo -e "$DASH_SEPERATOR"
					echo -e "$EQUAL_SEPERATOR"
					echo "Test results:"
					echo -e "\e[31;1mwrong answer detected!\e[0m"
					TESTING_END=$(($(date +%s%N) / 1000000))
					time=$((TESTING_END - TESTING_START))
					echo -e "\e[35;1mAll Testing finished in $time ms\e[0m"
					exit 0
				fi
			fi
			printf "Run Time: "
			if [ $time -gt $timeLimit ]; then
				tle=true
				echo -e "\e[31;1m$time\e[0m ms"
			else
				echo -e "\e[32;1m$time\e[0m ms"
			fi
		fi
		if [ $time -gt $maxTime ]; then
			maxTime=$time
		fi
		echo -e "$DASH_SEPERATOR"
	done
fi

cleanup
echo -e "$EQUAL_SEPERATOR"
printf "Results: "

if $rte; then
	echo -e "\e[31;1mrun time error\e[0m"
else
	if $allPassed; then
		if $tle; then
			echo -e "\e[31;1mtime limit exceeded\e[0m"
		else
			printf "\e[32;1maccepted\e[0m"
			echo -e " in \e[32;1m$maxTime\e[0m ms."
		fi
	else
		echo -e "\e[31;1mwrong answer\e[0m"
	fi
fi
TESTING_END=$(($(date +%s%N) / 1000000))
time=$((TESTING_END - TESTING_START))
if [ "$compact" = "false" ]; then
	echo -e "\e[35;1mAll Testing finished in $time ms\e[0m"
fi
