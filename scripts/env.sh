#!/bin/bash
# Source this file for shell helpers

proj=$(realpath $(dirname $0)/..)

function ark-build() {
    . $proj/scripts/build.sh $@
}

function ark-run() {
    mode=${1:-"Debug"}

    $proj/build/$mode/arkrt
}
