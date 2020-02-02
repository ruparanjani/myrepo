#include<stdio.h>
#include<stdlib.h>
#include "cpfapi.h"
void id_validation(char* str){
	int buffer =0;
	buffer = atoi(str);
	if(buffer > 6000){
		buffer=buffer-5000;
		printf("\nexisting user and your uid is : %d",buffer);
	}
	else if(buffer >= 1001 && buffer <3000)
		printf("\nyour uid id %d\n ",buffer);
	else if(buffer >= 3001 && buffer < 6000)
		printf("\nyour Sid is %d\n",buffer);
}
