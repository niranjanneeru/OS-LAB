# Write a shell script program to test whether a string is present in a file or not

if grep -q $2 $1;then
    echo "Found"
else
    echo "Not Found"
fi