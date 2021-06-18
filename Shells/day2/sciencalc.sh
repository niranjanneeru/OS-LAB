#!/bin/bash

read -p "Enter the Expression to Compute: " str

prev=0
set=0
op=0
flag=1
re='^[0-9]+$'
str="$str+"

for (( i = 0 ; i < ${#str} ; i++ )); do
    char=${str:$i:1}
    if [[ $char == + || $char == - || $char == "x" || $char == "/" || $char == "e" || $char == "%" ]]
    then
        if [[ $flag == 1 ]]
        then
            if [[ $op == + ]]
            then
                prev=$(($prev + $set))
            elif [[ $op == - ]]
            then
                prev=$(($prev - $set))
            elif [[ $op == "x" ]]
            then
                prev=$(($prev * $set))
            elif [[ $op == "/" ]]
            then
                prev=$(($prev / $set))
            elif [[ $op == "e" ]]
            then
                prev=$(($prev ** $set))
            elif [[ $op == "%" ]]
            then
                prev=$(($prev % $set))
            else
                prev=$set
            fi
            set=0
            flag=0
            op=$char
        else
            echo "Invalid Syntax"
            exit
        fi
    elif [[ $char =~ $re ]]
    then
        set=$(($set*10+$char))
        flag=1
    else
        echo "Invalid Syntax"
        exit
    fi
done

echo $prev