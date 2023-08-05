#!/bin/bash

output=employee.txt
while true
do
echo """

Employee Record Management Menu:
1)Enter a record
2)Search a record
3)Delete the record
4)Sort the records
5)List all the records
6)Exit
"""
echo -n "Enter choice(1-6):"
read choice
case $choice in
    1)
        echo "Enter the Employee name: "
        read name
        echo "Enter the Employee number: "
        read number
        echo "Enter the Employee phone number: "
        read phn
        record="$name $number $phn"
        echo "$record" >> $output
        ;;
    2)
        echo "Enter the Employee name to search for: "
        read name
        rec=$(grep $name $output)
        echo $rec
        ;;
    3)
        echo "Enter the Employee name to delete for: "
        read name
        rec=$(grep -v $name $output)
        if($rec)
        then
            echo "$rec" > temp.txt
            cat temp.txt > $output
        else
            echo "No matching records found"
        fi
        ;;
    4)
        echo "Sort the record by name "
        rec=$(sort $output)
        echo $rec
        ;;
    5)
        echo "List the records: "
        cat $output
        ;;
    6)  
        echo "Exiting"
        break
        ;;

esac
done