#!/bin/bash

createAddressBook() {
    if [ -e addressbook.txt ]; then
        echo "Address book already exists."
    else
        touch addressbook.txt
        echo "Address book created."
    fi
}

insertRecord() {
    while true; do
        echo "To add a record in the address book, please insert in the following format:"
        echo "Format: \"Last name,first name,email,phone number\" (no quotes or spaces)."
        echo "To quit, type 'q'."
        read aInput
        if [ "$aInput" == 'q' ]; then
            break
        else
            echo "$aInput" >> addressbook.txt
            echo "Record inserted."
        fi
    done
}

viewRecord() {
    while true; do
        echo "To display a record, enter the last name of the person (case sensitive)."
        echo "To quit, type 'q'."
        read dInput
        if [ "$dInput" == 'q' ]; then
            break
        fi
        echo "Displaying record for $dInput:"
        grep "$dInput" addressbook.txt
        if [ $? -ne 0 ]; then
            echo "No record found."
        fi
    done
}

searchRecord() {
    while true; do
        echo "To search for a record, enter the last name of the person (case sensitive)."
        echo "To quit, type 'q'."
        read dInput
        if [ "$dInput" == 'q' ]; then
            break
        fi
        echo "Searching for record of $dInput:"
        grep "$dInput" addressbook.txt
        if [ $? -ne 0 ]; then
            echo "No record found."
        fi
    done
}

deleteRecord() {
    while true; do
        echo "To delete a record, enter the last name or email of the person (case sensitive)."
        echo "To quit, type 'q'."
        read rInput
        if [ "$rInput" == 'q' ]; then
            break
        fi

        echo "Matching records for \"$rInput\":"
        grep -n "$rInput" addressbook.txt
        if [ $? -ne 0 ]; then
            echo "No record found."
        else
            echo "Enter the line number of the record to delete:"
            read lineNumber
            sed -i "${lineNumber}d" addressbook.txt
            echo "Record deleted from address book."
        fi
    done
}

# Main program menu with options
while true; do
    echo "Address Book Menu"
    echo "Enter your choice:"
    echo "1 --> Create Address Book"
    echo "2 --> Insert Record"
    echo "3 --> View Record"
    echo "4 --> Search Record"
    echo "5 --> Delete Record"
    echo "6 --> Exit"
    read input
    case $input in
        1) createAddressBook ;;
        2) insertRecord ;;
        3) viewRecord ;;
        4) searchRecord ;;
        5) deleteRecord ;;
        6) echo "Exiting program."; exit 0 ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
done





chmod +x pr1.sh
./pr.sh
