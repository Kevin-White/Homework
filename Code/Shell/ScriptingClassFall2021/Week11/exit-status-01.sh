#!/bin/bash

HOST="google.com"

ping -c 1 $HOST
# echo $?
# $? is used to find the return value of the last executed command
if [ "$?" -eq "0" ]
then
 echo "$HOST reachable."
else
 echo "$HOST unreachable."
fi

