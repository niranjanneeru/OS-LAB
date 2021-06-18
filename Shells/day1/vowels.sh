# Write a shell script program to read a line from a file and store them into
# another file after converting all the vowels from first file into uppercase.

# !/bin/bash

head "$1" -n 1 | tr 'aeiou' 'AEIOU' > vowel.txt