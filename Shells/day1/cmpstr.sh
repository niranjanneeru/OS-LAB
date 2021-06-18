# Write a shell script program to check whether two strings sent as command
# line arguments are same or not using test command.

# !/bin/bash

[[ $1 == $2 ]] && echo "Equal" || echo "Not Equal"