#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>
#include "cpfapi.h"
int sid_retrive() 
{ 
	char buff[1024],*str;
     	int count=0,last=0,i=0,sid=0;
     	FILE *fp = fopen("service_reg_table.csv","r");
     	char* token;
     	while(fgets(buff,1024,(FILE*)fp)){
		count++;
	}
     	fclose(fp);
     	last=--count;
     	fp = fopen("service_reg_table.csv","r");
	count=0;
     	while(fgets(buff,1024,(FILE*)fp)){
		count++;
	     	printf("\n%s",buff);
	     	if(count==last){
			token=strtok(buff,",");
			sid=atoi(token);
			printf("\ntoken : %s ,sid :%d",token ,sid);
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
