#!/bin/bash

cd www/
for FILE in *.html
do
    echo "Copying $FILE"
    cp $FILE ../www_bk/test.html
done
