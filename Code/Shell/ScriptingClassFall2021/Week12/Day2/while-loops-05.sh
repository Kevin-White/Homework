#!/bin/bash

#grep xfs /etc/fstab | while read LINE
cat /etc/fstab | while read LINE
do
  echo "xfs: ${LINE}"
done
