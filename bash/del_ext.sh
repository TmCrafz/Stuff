#!/bin/bash
# Delete files with the given extension
if [ -z "$1" ]
    then
        echo "No extension specified"
        exit 1
fi
echo Find files which extension: $1
find . -name "*.$1" -type f
read -p "Delete? [Y/n]" input
if [ $input == 'Y' ]
    then
        find . -name "*.$1" -type f -delete
fi

