# Write a shell script program that take first 10 lines from first file and rest 10
# lines from second file and move them in a third file. The filename will be sent
# as command line arguments.

head $1 > $3
tail $2 >> $3
