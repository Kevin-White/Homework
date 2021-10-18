#!/bin/bash
# mkdir www
# mkdir www_bk
# cp copy*.sh www/
cd www
for f in *.sh; do 
    mv -- "$f" "${f%.sh}.html"
done