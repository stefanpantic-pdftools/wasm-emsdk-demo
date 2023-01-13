#!/bin/sh

rm -rf build
mkdir build
cd build
emcmake cmake -DCMAKE_BUILD_TYPE=Debug . ../
cmake --build . --config Debug
make install
