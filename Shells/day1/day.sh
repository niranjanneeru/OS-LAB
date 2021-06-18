# .Menu driven program to display the day when inputting 1 to 7

# !/bin/bash

while :
do
    read -p "Enter a number in between 1 and 7 (including them) I will return you the day(any other to quit): " day

    case $day in
        1) echo "Monday";;
        2) echo "Tuesday";;
        3) echo "Wednesday";;
        4) echo "Thursday";;
        5) echo "Friday";;
        6) echo "Saturday";;
        7) echo "Sunday";;
        *) echo "Quiting..."
        exit;;

    esac

done