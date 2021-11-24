#!/bin/bash

tablica=($(ls -l))





regex='^[0-9][0-9][_][0-9][0-9][_][0-9][0-9]$'
if [[ $incoming_string =~ $regex ]]
then
  # Do awesome stuff here
fi
