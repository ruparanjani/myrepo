#include<stdio.h>
#include<stdlib.h>
#include "cpfapi.h"
void id_validation(char* str){
	int buffer =0;
	//printf("\nstr %s ",str);
	buffer = atoi(str);
	printf("\nbuffer %d ",buffer);
	if(buffer == 10)
		printf("\nexisting user\n");
	else if(buffer >= 1001 && buffer <3000)
		printf("\nyour uid id %d\n ",buffer);
	else if(buffer >= 3001 && buffer < 6000)
		printf("\nyour Sid is %d\n",buffer);
}
