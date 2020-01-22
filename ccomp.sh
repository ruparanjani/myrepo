#!/bin/bash

rm   -f client.o id_validation.o
gcc -c client.c 
gcc -c id_validation.c
ar rs libid.a id_validation.o
gcc -o client -L. client.o -lid
