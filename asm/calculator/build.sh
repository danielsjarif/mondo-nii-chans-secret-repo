#!/bin/bash
 
clear
 
nasm -felf64 calc-ops.asm
gcc calc-ops.o add.c -o add.out
gcc calc-ops.o gcd.c -o gcd.out
gcc calc-ops.o subtract.c -o subtract.out
echo To call each function say [add, gcd, subtract].out {arg1} {arg2}