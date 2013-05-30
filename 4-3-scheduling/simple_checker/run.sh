#!/bin/sh

doit() {
    ./gen.py > input.txt
    cp input.txt o2cmax.in

    ./qTaskB
    java Main

    rm o2cmax.in
    diff output.txt o2cmax.out
}

while doit; do
    echo ok
done;
