#!/bin/bash

clear

ROOT=$(realpath "$1")
source "$CPS_PATH/project_config"

if [ ! -f "$ROOT/config.json" ]; then
  echo "[CPS] Error, no config.json file found. Please create one" 
  if [ -f "$TEMPLATE_PATH/config.template" ]; then
    echo "Sample config: "
    cat "$TEMPLATE_PATH/config.template"
  fi
  exit
fi

cd "$CPS_PATH" || exit

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
