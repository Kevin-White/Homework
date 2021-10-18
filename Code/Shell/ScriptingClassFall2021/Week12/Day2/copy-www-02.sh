#!/bin/bash

for FILE in /www/*.html
do
    echo "Copying $FILE"
    cp $FILE ../www_bk/copyOf-$FILE
done
