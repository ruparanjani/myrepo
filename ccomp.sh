#!/bin/bash

rm   -f client.o id_validation.o reg_user_validation.o svc_reg_validation.o validation_ser_reg.o
gcc -c client.c 
gcc -c id_validation.c reg_user_validation.c svc_reg_validation.c validation_ser_reg.c
ar rs libuid.a id_validation.o reg_user_validation.o svc_reg_validation.o validation_ser_reg.o
gcc -o client -L. client.o -luid
