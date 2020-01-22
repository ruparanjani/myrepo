#!/bin/bash

rm   -f ci.o reg_user.o server.o itoa.o server libuim.a
gcc -c server.c
gcc -c ci.c reg_user.c itoa.c 
ar rs libuim.a ci.o reg_user.o itoa.o
gcc -o server -L. server.o -luim -lpthread

