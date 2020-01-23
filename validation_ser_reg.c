#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <regex.h>
#include<ctype.h>
#include<stdbool.h>
#include "validation.h"
#define MAX 255
int main_validation(char *cBuffer)
{
	int len=0,i=0;
	char *command = NULL;
	command=(char*)malloc(MAX*sizeof(char));
	len=strlen(cBuffer);
	if(len==1)
		printf("\n no input");
	else{
		while((cBuffer[i] != ':') && (i<len)){
			command[i] = cBuffer[i];
			i++;
		}

		command[i]='\0';
		//printf("\n command=%s",command);
		if(strcmp(command,"REG_USR")==0){
			
			return reg_usr_validation(cBuffer);
		}
		else if(strcmp(command,"REG_SVC")==0){
			//printf("\n reg_svc matched");
			return reg_svc_validation(cBuffer);
		}
		else if(1){
			printf("\n no proper input");
			
		}
	}
}
