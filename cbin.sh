#!/usr/bin/bash

if [ ! -d bin ]
then
    mkdir bin
fi

clang playground.c -o ./bin/playground -lm 
./bin/playground
