#!/bin/bash

read -p "Enter y or n:" ANSWER

case "$ANSWER" in
    [yY][eE][sS])
        echo "You answered yes."
        ;;
    [nN]|[nN][oO])
        echo "You answered no."
        ;;
   *)
        echo "Invalid answer."
        ;;
esac
