#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>
#include "cpfapi.h"

int sid_retrive() 
{ 
	char buff[1024],*str,*token;
     	int count=0,last=0,i=0,sid=3000;
     	FILE *fp = fopen("service_reg_table.csv","r");
	if(fp==NULL){
		printf("\nCan't open the file\n");
	}
     	while(fgets(buff,1024,(FILE*)fp)){
		count++;
	}
     	fclose(fp);
     	last=--count;
     	fp = fopen("service_reg_table.csv","r");
	if(fp==NULL){
		printf("\nCan't open the file\n");	
	}	
	count=0;
     	while(fgets(buff,1024,(FILE*)fp)){
		count++;
	     	if(count==last){
			token=strtok(buff,",");
			sid=atoi(token);
	     	}
	}
	return sid;
}
/*void main()
{
int i;
i=uid_retrive();
printf("\ni=>%d",i);
}*/
