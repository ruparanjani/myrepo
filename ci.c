#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "cpfapi.h"

char* User_Validation(char *cInput_Buffer)
{
	int i=0,iUid,len=4;
	char *str;
	bool flag=false;
      
	printf("cInput_Buffer =>%s",cInput_Buffer);
	str=(char*)malloc(10*sizeof(char));
	while(cInput_Buffer[i]!='\0'){
		if(cInput_Buffer[i]==':'){
			flag=true;
			break;
		}
			i++;
	}
	if(flag){
		iUid=Command_Interpreter(cInput_Buffer);
		getDecStr (str,len,iUid);
		printf("%s",str);
		return(str);
	}
		//	else
//		Uid_Validation(cInput_Buffer);*/
	return NULL;
}

int Command_Interpreter( char *cInput_Buffer )
{
	char cCommand[100],cInput_Fields[150];
	int iOpt=0,iLength=0,i=0,iCommand_Length=0,j=0,sid;
	int iUid=1000;
	iLength=strlen(cInput_Buffer);

	while(cInput_Buffer[iCommand_Length]!=':')
		iCommand_Length++;

	for(i=0;i<iCommand_Length;i++)
		cCommand[j++]=cInput_Buffer[i];
	
	printf("\ncCommand =>%s",cCommand);
	cCommand[++j]='\0';
	j=0;	

	for(i=iCommand_Length+1;cInput_Buffer[i]!='\0';i++)
		cInput_Fields[j++]=cInput_Buffer[i];

	printf("\ncInput_Fields =>%s",cInput_Fields);
	cInput_Buffer[++j]='\0';

	if(strcmp(cCommand,"REG_USR")==0){
		return uim_reg_usr(cInput_Fields);
	}
	/*
	 if(strcmp(cCommand,"REG_SVC")==0){	
                 sid=svc_reg(cInput_Fields,iUid);
		 return sid;
		 //printf("service id :%d",sid);
	}	 		

	if(strcmp(cCommand,"GET_SVC_LIST")==0)
		svcmgr_get_svc_list(cInput_Fields);

	else if(strcmp(cCommand,"SUBSCRIBE")==0)
		sub_subscribe(cInput_Fields);
	else if(strcmp(cCommand,"START_SESSION")==0)
		start_session(cInput_Fields);
	else if(strcmp(cCommand,"END_SESSION")==0)
		end_session(cInput_Fields);*/
//	return(cInput_Buffer);

	return -1;
}
