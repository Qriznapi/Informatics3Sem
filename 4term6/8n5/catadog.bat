@echo off

gcc -c -DUPPERCASE alice.c -o alice.o

gcc -c bob.c -o bob.o

gcc -c main.c -o main.o

gcc main.o alice.o bob.o -o program.exe
