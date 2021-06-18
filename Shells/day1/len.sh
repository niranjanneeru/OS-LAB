# Write a shell script program that accept the name of the user and prints the
# entire name in reverse and also print the length of the entire name

# !/bin/bash

read -p "Enter your name: " name
len=${#name}
reverse=""

for ((i = $len - 1; i >= 0; i--))
do
    reverse="$reverse${name:i:1}"
done
echo "Name Reversed $reverse"
echo "Length of the name : ${len}"