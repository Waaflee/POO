#!/bin/bash
touch meson.build
killall server
cd build
clear
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#}
ninja
echo ""
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#}
./server &
./client localhost 8080 < ../input
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#}
