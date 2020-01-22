#!/bin/bash

rm   -f ci.o reg_user.o server.o itoa.o backup_svcreg.o server libuim.a
gcc -c server.c
gcc -c ci.c reg_user.c itoa.c backup_svcreg.c
ar rs libuim.a ci.o reg_user.o itoa.o backup_svcreg.o
gcc -o server -L. server.o -luim -lpthread

