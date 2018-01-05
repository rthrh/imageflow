#!/bin/bash

cmake_command="cmake .. -DCMAKE_BUILD_TYPE=DEBUG"
ls
mkdir -p build
cd build
rm -rf *
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8
