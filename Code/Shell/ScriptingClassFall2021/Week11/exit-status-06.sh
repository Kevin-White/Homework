#!/bin/bash

HOST="6165451546481654546google.com"

ping -c 1 $HOST

if [ "$?" -ne "0" ]
then
  echo "$HOST unreachable."
  exit 1
fi

exit 0
