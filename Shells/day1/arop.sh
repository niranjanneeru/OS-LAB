#!/bin/bash

#Write a shell script program to perform arithmetic operation on two numbers

read -p "Enter the 1st number: " a
read -p "Enter the 2nd number: " b
read -p "Enter the operation you want to perform (+ or - or x or /): " o

echo -n "$a $o $b = " 

if [ $o == 'x' ]
then
    echo $(($a * $b))
elif [ $o == - ]
then
    echo $(($a - $b))
elif [ $o == + ]
then
    echo $(($a + $b))
elif [ $o == / ]
then
    echo $(($a / $b))
else
    echo "$o is not a valid operation"
fi