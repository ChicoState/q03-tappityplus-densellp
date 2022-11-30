#!/bin/bash

make clean
make
./tappityTest
gcov -b tappity.cpp