#!/bin/bash

echo ""
echo "TEST: 2 args, no options"
echo "./app.exe one two"
./app.exe one two

echo ""
echo "TEST: 2 args with -o option"
echo "./app.exe -o one two"
./app.exe -o one two

echo ""
echo "TEST: no args"
echo "./app.exe"
./app.exe

echo ""
echo "TEST: -o option, no args"
echo "./app.exe -o"
./app.exe -o
