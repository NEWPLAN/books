#!/bin/bash
gcc -m32 -c *.c -fno-stack-protector

ld -e main -m elf_i386 *.o -o ab 
