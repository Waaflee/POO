#!/bin/bash
touch meson.build
cd build
clear
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#}
ninja test
myString=$(printf "%$(echo $COLUMNS)s");echo ${myString// /#} 