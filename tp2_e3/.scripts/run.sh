#!/bin/bash
touch meson.build
cd build
clear
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#}
ninja
echo ""
./main
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#}
