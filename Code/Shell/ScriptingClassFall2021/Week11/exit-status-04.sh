#!/bin/bash

HOST="google.com"

ping -c 1 $HOST && echo "$HOST reachable."

# cmd1 && cmd2, cmd2 only exicuted if cmd 1 is successfull.

