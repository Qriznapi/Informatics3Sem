@echo off

gcc -E hello.c -o hello.i

gcc -S hello.i -o hello.s

gcc -c hello.s -o hello.o

gcc hello.o -o hello.exe