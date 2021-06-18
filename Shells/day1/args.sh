#Write a shell script program to pass arguments to the program and display the
#count of arguments and content.

# !/bin/bash

echo "No. of Command Line Arguments: $#"

for i in $@
do
    echo "$i"
done