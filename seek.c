#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>

int uid_retrive() 
{ 
	char buff[1024],*str;
     	int count=0,last=0,i=0;
     	FILE *fp = fopen("uid_table.csv","r");
     	char* token;
     	while(fgets(buff,1024,(FILE*)fp)){
		count++;
	}
     	fclose(fp);
     	last=--count;
     	fp = fopen("uid_table.csv","r");
	count=0;
     	while(fgets(buff,1024,(FILE*)fp)){
		count++;
	     	printf("%s",buff);
	     	if(count==last){
			token=strtok(buff,",");
			for(;i<=3;i++)
				str[i]=token[i];
			str[i]='\0';
			break;	
	     	}
	}
	return(atoi(str));
}
