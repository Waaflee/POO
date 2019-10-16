#!/bin/bash
cd build
clear
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#} 
ninja
echo ""
./main $COLUMNS $ROWS
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#} 