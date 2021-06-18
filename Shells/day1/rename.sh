# 6. a) Let argument be a filename. Write a shell script program to check whether
# the file exist or not.
# b) Modify the above program to rename a filename with another name passed
# as argument, Also check number of parameters being passed.

if [[ -f $1 ]];then
    if [[ -f $2 ]];then
        echo "Already a file exist with that name"
        read -p "Do you want to overwrite?(y/N): " choice
        case "$choice" in 
            "y"|"YES"|"Y"|"yes")
                mv $1 $2
                echo "Rename Completed";;
            *);;
        esac
    else
        mv $1 $2
        echo "Rename Completed"
    fi
else
    echo "File Doesn't Exist"
fi