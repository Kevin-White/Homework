#!/bin/bash

HOST="google.com"

ping -c 1 $HOST || echo "$HOST unreachable."

# || : It's equivalent to boolean "or" with short-circuiting evaluation, 
# such that it will execute the second command only if the first returns 
# some value corresponding to "false"

# cmd1 && cmd2, cmd2 will only exicute if cmd1 is false

