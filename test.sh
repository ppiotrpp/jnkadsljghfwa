#!/bin/bash

while IFS=, read -r col1 col2 col3 col4
do
    out=`./solution $col2`
    if [ $out != $col3 ]; then
    echo "fail"
    echo "$col1\n$out\n$col3"
    fi
done < dataset.csv
