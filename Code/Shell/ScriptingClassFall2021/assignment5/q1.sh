echo "Enter a number: "

read num1

echo "enter a larger number: "

read num2

i=$num1
echo "-----------------"
while [ $i -le $num2 ]
do
 if [ $i -eq 1 ]
 then
  echo "one"
 elif [ $i -eq 2 ]
 then
  echo "two"
 elif [ $i -eq 3 ]
 then
  echo "three"
 elif [ $i -eq 4 ]
 then
  echo "four"
 elif [ $i -eq 5 ]
 then
  echo "five"
 elif [ $i -eq 6 ]
 then
  echo "six"
 elif [ $i -eq 7 ]
 then
  echo "seven"
 elif [ $i -eq 8 ]
 then
  echo "eight"
 elif [ $i -eq 9 ] 
 then
  echo "nine"
 elif [ $((i%2)) -eq 0 ]
 then
  echo "even"
 else
  echo "odd"
 fi
 i=$(($i+1))
 done