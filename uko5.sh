#!/bin/bash
TASKS_FILE=tasks.txt


function Add() {

    if test "$#" -lt 1; then
        echo "At least one parameter required" >&2 
	 return 1
    fi

    if ! test -f "$TASKS_FILE"; then
        echo "$TASKS_FILE does not exist. Creating"
        touch "$TASKS_FILE"
    fi
	for value in "$@"; do
	 echo "$value" >> $TASKS_FILE
  	done
 	return 0
}

function Get() {
	echo "$@"
	local lines=1
   	      if test "$#" -gt 0; then
		if test "$#" -ne 2; then
		  echo "Error. Number of parameters must equal 2"
		  return 1
	fi

	if test "$1" != "-n"; then
   		echo "Error. Unknown parameter $1"
		return 1
	fi

	if test "$2" -lt 1; then
		echo "Error. Number must be positive."
		return 1
	fi
	local lines="$2"
    fi

    if ! test -f "$TASKS_FILE"; then
        echo "$TASKS_FILE does not exit. Exiting"
        return 1
    fi

         task=$(head -n $lines $TASKS_FILE)
         if [ -z "$task" ]; then
           echo "There is no tasks in a list. Exiting"
           return 1
    fi


    echo $task
    sed -i "1,$lines d" $TASKS_FILE
    return 0

}

function Find() {

    if test "$#" -ge 1; then
        echo "At least one parameter required" >&2
        exit
    fi

    if ! test -f "$TASKS_FILE"; then
        echo "$TASKS_FILE does not exit. Exiting"
        return 1
    fi

    if [ -z $(head -n 1 $TASKS_FILE) ]; then
        echo "There is no tasks in a list. Exiting"
        return 1
    fi

	for value in "$@"; do
   	    cat $TASKS_FILE | grep -wx "$value" 
	done
	return 0

}

function All() {

    if ! test -f "$TASKS_FILE"; then
           echo "$TASKS_FILE does not exit. Exiting"
           return 1
    fi
    cat $TASKS_FILE
    return 0
}

if test "$1" == "Add"; then
    Add "${@:2}"
fi

if test "$1" == "Get"; then
        Get "${@:2}"
fi

if test "$1" == "Find"; then
    Find "${@:2}"
fi

if test "$1" == "All"; then
    All
fi

if test "$1" == "interactive"; then

PS3='Please enter your choice: '
options=("Add" "Get" "Find" "All" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Add")
            echo "you chose $opt"
		read parameter
		Add $parameter
            ;;
        "Get")
            echo "you chose $opt"
		read parameter
		Get $parameter
            ;;
        "Find")
            echo "you chose $opt"
           	read parameter
		Find $parameter
            ;;
	"All")
	    echo "you chose $opt"
        	All
	    ;;
	"Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done
fi
