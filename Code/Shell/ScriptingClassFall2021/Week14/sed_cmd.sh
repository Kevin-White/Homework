cat file3.txt
echo "----------------------------"
sed 's/unix/linux/' file3.txt
echo "----------------------------"
sed 's/unix/linux/2' file3.txt
echo "----------------------------"
cat file3.txt

echo "Welcome To The Geek Stuff" | sed 's/\(\b[A-Z]\)/\(\1\)/g'