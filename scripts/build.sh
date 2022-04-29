#!/bin/bash

proj=$(realpath $(dirname $0)/..)

mode=${1:-"Debug"}

build=$proj/build/$mode

echo "Building mode '${mode}'"

if [ ! -d $build ]; then
    cmake \
        -DCMAKE_BUILD_TYPE=$mode \
        -S $proj \
        -GNinja \
        -B $build
fi

cmake --build $build
