#!/bin/bash
name[0]="zero"
name[1]="one"
name[2]="two"
ind=2
echo ${name[ind]}

# Alernative ways to print elements from a particular index
# echo ${arr[@]:0}	
# echo ${arr[@]:1}
# echo ${arr[@]:2}	
# echo ${arr[0]:1}	
# To print elements in range
# echo ${arr[@]:1:4}     
# echo ${arr[@]:2:3}     
# echo ${arr[0]:1:3}   

echo OR

for num in ${name[@]}
do
  echo "num: $num"
done

