# Consider a file school.dat with the following fields: roll no, name and marks.
# Write a shell script program to sort the file in descending order of marks

i=0
while IFS="," read -r rollno name marks
do
    if [[ $i == 0 ]]
    then
        ((i++))
        echo -n "">".tmp.txt"
    else
        echo "$marks $rollno $name $marks" >> ".tmp.txt"
    fi
done < school.dat

cat ".tmp.txt" | sort -r

rm ".tmp.txt"