#!/bin/bash

rm   -f ci.o reg_user_mailid1.o server.o itoa.o backup_svcreg.o seek1.o sseek.o server libuim.a
gcc -c server.c
gcc -c ci.c reg_user_mailid1.c itoa.c backup_svcreg.c seek1.c sseek.c
ar rs libuim.a ci.o reg_user_mailid1.o itoa.o backup_svcreg.o seek1.o sseek.o 
gcc -o server -L. server.o -luim -lpthread

