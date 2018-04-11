#!/bin/bash

# usage: bash runner.sh filename
# exmaple: bash runner.sh abc086C

g++ -Wall "$1.cpp"

for input in $(echo "$1".input*); do
    echo "$input"
    cat "$input" | ./a.out
done
