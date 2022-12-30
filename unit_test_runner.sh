#!/usr/bin/env bash

echo "compiling"
g++ -std=c++11 -g -Wall -Werror -pedantic-errors -ggdb3 -DNDEBUG ./unit_tests/*.cpp ./your_files/*.cpp -o unit_test_exec
echo "finish compiling"
echo "running"
./unit_test_exec
echo "finish running"