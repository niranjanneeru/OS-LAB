# Write a shell script program to show number of files in the current directory
# beginning with a specified character

# !/bin/bash

ls | grep "^$1" 