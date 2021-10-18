
function newDir() {
cd $1
FILE=$(ls)
find


}

function find() {
for F in $FILE
do
if [ -d "$F" ]
then
  echo "directory: $F"
  new=$F
  newDir $new
elif [ -f "$F" ]
then
  echo "file: $F"
  if [[ $F == *.py ]]
  then
    python $F
  fi
else
  echo "$F is something other than a regular file or directory."
fi
done
}

FILE=$1
cd $FILE
FILE=$(ls)
find 