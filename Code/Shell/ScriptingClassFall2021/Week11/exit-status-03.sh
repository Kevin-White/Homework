#!/bin/bash

HOST="google.com"

ping -c 1 $HOST
RETURN_CODE=$?
#$? is the output of the last command that was run

if [ "$RETURN_CODE" -ne "0" ]
then
  echo "$HOST unreachable."
fi

