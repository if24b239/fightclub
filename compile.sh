#! /usr/bin/bash

_source_files=$(find source/ -type f -name "*.cpp")
echo $_source_files
g++ -Wall -fsanitize=address -Iinclude $_source_files -o outFile