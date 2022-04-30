#!/bin/bash

proj=$(realpath $(dirname $0)/..)

mode=${1:-"Debug"}

build=$proj/build/$mode

echo "Building mode '${mode}'"

cmake \
    -DCMAKE_BUILD_TYPE=$mode \
    -S $proj \
    -B $build

cmake --build $build
