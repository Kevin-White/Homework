#!/bin/bash

function hello() {
    echo "Hello!"
    now
}

function now() {
     echo "It's $(date +%r)"
     # To display locale’s 12-hour clock time, enter
     # more details about display time and date: 
     # https://www.cyberciti.biz/faq/linux-unix-formatting-dates-for-display/
     
}

hello
