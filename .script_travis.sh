#!/bin/bash

docker run \
     $ci_env -e WITH_COVERAGE -e CC -e CXX -e DISPLAY=:10 --privileged --cap-add=ALL \
     -v `pwd`:/root/sources rthrh/imflow /bin/bash \
     -c "source /opt/qt59/bin/qt59-env.sh && cd ~/ && rm -rf imageflow && git clone https://github.com/rthrh/imageflow.git && cd imageflow && git submodule update --init --recursive && mkdir build && cd build && cmake .. && make"

