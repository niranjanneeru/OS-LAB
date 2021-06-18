# Write a shell script program to test whether 3 arguments are being passed to it
# !/bin/bash

if [ $# == 3 ]
then
    echo -n "[PASSED]"
else
    echo -n "[FAILED]"
fi

echo " $# Arguments are passed"
