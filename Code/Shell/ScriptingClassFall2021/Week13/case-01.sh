#!/bin/bash

case "$1" in
    start)
        #/usr/sbin/sshd
        ls
        ;;
    disp)
        #kill $(cat /var/run/sshd.pid)
        cat case-01.sh
        ;;
esac
