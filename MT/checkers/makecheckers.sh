#!/bin/bash

me=`pwd`

pushd ../problems
for name in *
do
    rm "$name/check" "$name/checkcompile.sh" "$name/testlib4j.jar"
    cp "$me/check" "$me/checkcompile.sh" "$me/testlib4j.jar" $name
    pushd $name
    ./checkcompile.sh
    mkdir "$me/$name"
    cp Check.jar "$me/$name"
    popd
done
