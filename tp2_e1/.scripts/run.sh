#!/bin/bash
cd build
clear
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#} 
ninja
echo ""
./main
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#} 