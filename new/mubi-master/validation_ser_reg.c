#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <regex.h>
#include<ctype.h>
#include<stdbool.h>
#include "validation.h"
#define MAX 255
int main_validation(char *cBuffer,int uid)
{
	int len=0,i=0,val_command=0;
	char *command = NULL;
	bool flag1=false;
	command=(char*)malloc(MAX*sizeof(char));
	len=strlen(cBuffer);
	if(len==1)
		printf("\n Please,Enter command\n");
	else{
		while(cBuffer[i] != ':') {
			if(i<len){
				command[i++] = cBuffer[i];
				
			}
			else{
				printf("\n Sorry,Give proper command\n");
				flag1=true;
				break;
			}
		}
		if(flag1==false){
			val_command=command_checking(command);
			if(val_command==1){
				command[i]='\0';
			}
			else{
				printf("\n Please Enter valid command\n");
			}


			if(strcmp(command,"REG_USR")==0){
			
				 return reg_usr_validation(cBuffer);
			}
			else if(strcmp(command,"REG_SVC")==0){
				return reg_svc_validation(cBuffer,uid);
			}
			else{
				printf("\n Sorry,Please check your command \n");
			}

		}
	}	
		free(command);
}

int command_checking(char *str)
{
	bool flag1=false;
	int i=0;
		for(i=0;i<strlen(str);i++){
                                if((isupper(str[i])) || (str[i]=='_')){
                                        continue;
                                }
                                else{
                                        flag1=true;
                                        break;
                                }
                        }
		

        	 if (flag1==false) 
                	return 1;
         	 
		 else
			 return 0;
}
