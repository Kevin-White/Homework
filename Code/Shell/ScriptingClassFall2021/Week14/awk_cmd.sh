
#Prints every line
awk '{print}' brother.txt

#prints every line with "teen"
awk '/teen/ {print}' brother.txt

#Prints first and 4th argument of every line
awk '{print $1,$4}' brother.txt

#Prints first and 4th argument for "teen"s
awk '/teen/ {print $1,$4}' brother.txt

#Shows number from every line
awk '{print NR,$0}' brother.txt

#Shows first and last
awk '{print $1,$NF}' brother.txt

#if the line number is between 2 and 3
awk 'NR==2, NR==3 {print NR,$0}' brother.txt


#if last value is biger than 40000
awk '$NF > 40000 {print $1,$NF}' brother.txt