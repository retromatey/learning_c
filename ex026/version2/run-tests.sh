#!/bin/bash

echo ""
echo "TEST: 2 args, no options"
echo "./app.exe int void"
./app.exe int void

echo ""
echo "TEST: 2 args with -o option"
echo "./app.exe -o int void"
./app.exe -o int void

echo ""
echo "TEST: no args"
echo "./app.exe"
./app.exe

echo ""
echo "TEST: -o option, no args"
echo "./app.exe -o"
./app.exe -o
