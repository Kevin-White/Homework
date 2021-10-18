#!/bin/bash


# Exit code 0        Success
# Exit code 1        General errors, Miscellaneous errors, such as "divide by zero" and other impermissible operations
# Exit code 2        Misuse of shell builtins (according to Bash documentation)  

ls
if [ "$?" -eq "0" ]
then
  echo "Command succeeded"
  exit 0
else
  echo "Command failed"
  exit 1
fi
