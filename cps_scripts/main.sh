#!/bin/zsh

clear

ROOT=$1:A
source "$CPS_PATH/project_config"

cd $CPS_PATH

case $2 in

  0) # run
    ./run.sh "$ROOT"
    ;;

  1) # run with debug
    ./run.sh "$ROOT" 1 # DEBUG_FLAG on
    ;;

  2) # run with terminal
    ./run_with_terminal.sh "$ROOT"
    ;;

  3) # config
    ./config.sh "$ROOT"
    ;;

  4) # archive 
    ./archive.sh "$ROOT"
    ;;

  5) # new 
    ./new.sh
    ;;

  *)
    echo -n "unknown"
    ;;
esac
