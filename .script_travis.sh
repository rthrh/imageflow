#!/bin/bash

cmake_command="cmake .. -DCMAKE_BUILD_TYPE=DEBUG"
ls
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8
