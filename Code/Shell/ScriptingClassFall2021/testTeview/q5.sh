function func {
 local a=$1 b=$2 c
 while (( a % b != 0 )) ; do
 c=$a ; a=$b ; (( b = c % b ))
 done
 echo "$b"
}
func 6 12