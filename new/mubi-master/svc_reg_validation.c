#include <stdio.h>
#include <regex.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 255
int  reg_svc_validation(char *str,int uid)
{
    int i=0,len=0,rv=0;
    len=strlen(str);
    str[len]='\0';
    const char* pattern = "[A-Z_]+:[a-zA-Z ]+,[a-zA-Z ]+,[a-zA-Z ]+,[0-9]";
    regex_t re;
	
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;

    int status = regexec(&re, str, 0, NULL, 0);
    regfree(&re);
 	if (status == 0) {
		  rv=svc_length_checking(str,uid);
			if(rv==1)

				return 1;
			else
				return 0;
	}
     	else
		svc_validate_buffer(str,uid);         	
    
    
}    
void svc_validate_buffer(char *cBuffer){
	bool flag1 = false,flag2=false,flag3=false,flag4=false;
	char *sName,*sType,*sStatus,*command,*Uid;
	sName=(char*)malloc(MAX*sizeof(char));
	sType=(char*)malloc(MAX*sizeof(char));
	sStatus=(char*)malloc(MAX*sizeof(char));
	command=(char*)malloc(MAX*sizeof(char));
	Uid=(char*)malloc(MAX*sizeof(char));
	memset(sName,0,sizeof(sName));
	memset(sType,0,sizeof(sType));
	memset(sStatus,0,sizeof(sStatus));
	memset(command,0,sizeof(command));
	memset(Uid,0,sizeof(Uid));
	int i=0,j=0,count=0,name=0,type=0,status=0,uid=0,iUid=0;
	if(cBuffer[0]!='\n'){
			
		while(cBuffer[i] != ':'){
			if(i<strlen(cBuffer)){
				command[j++] = cBuffer[i++];
				
			}
		}
		command[i]='\0';
		i++;
		j=0;

		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
			sName[j++] = cBuffer[i++];

		sName[j]='\0';
		name=strlen(sName);
		i++;
		j=0;
		
		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
        	                sType[j++] = cBuffer[i++];

                sType[j]='\0';
		type=strlen(sType);
                i++;
		j=0;


		while((cBuffer[i] != '\0') && (i<strlen(cBuffer)))
			sStatus[j++] = cBuffer[i++];

		sStatus[j]='\0';
		status=strlen(sStatus);
		j=0;
		
		while((cBuffer[i] != '\n') && (i<strlen(cBuffer)))
                        Uid[j++] = cBuffer[i++];

                Uid[j]='\0';
		uid=strlen(Uid);
		
		if(strlen(sName)!=0){
			for(i=0;sName[i]!='\0';i++){
				if(isalpha(sName[i]) || sName[i]==' '){
					continue;
				}
				else{
					flag1=true;
					break;
				}
			}
		}
		else{
			
			printf("\n Please enter service name");
		}

		if(flag1==true)
			printf("\n Sorry,Service name invalid");

		if(name>13)
			printf("\n Service Name should be maximum of 12 characters\n");


		 
		 if(strlen(sType)!=0){
                        for(i=0;sType[i]!='\0';i++){
                                if(isalpha(sType[i]) || sType[i]==' '){
                                        continue;
                                }
                                else{
                                        flag2=true;
                                        break;
                                }
                        }
                }
		else{
                        printf("\n Please enter service type");
                }


                if(flag2==true)
                        printf("\nSorry,service type invalid");

		 if(type>13)
                        printf("\n Service type should be maximum of 12 characters\n");


		 if(strlen(sStatus)!=0){
                        for(i=0;sStatus[i]!='\0';i++){
                                if(isalpha(sStatus[i]) || sStatus[i]==' '){
                                        continue;
                                }
                                else{
                                        flag3=true;
                                        break;
                                }
                        }
                }
		else{
                        printf("\n Please enter service status");
                }


                if(flag3==true)
                        printf("\n Sorry,service status invalid");

		 if(status>13)
                        printf("\n Service status should be maximum of 12 characters\n");


		 if(strlen(Uid)!=0){
                        for(i=0;Uid[i]!='\0';i++){
                                if(isdigit(Uid[i])){
                                        continue;

                                }
                                else{
                                        flag4=true;
                                        break;
                                }
                        }
			

                }
                else{
                        printf("\n Please enter UID");
                }
		
		

                if(flag4==true)
                        printf("\n Sorry,invalid UID");
		if(uid!=4)
			printf("\n UID must be 4 digit ,please enter valid uid");


	}
     }


int svc_length_checking(char *cBuffer,int reg_uid){
	bool flag1 = false,flag2=false,flag3=false,flag4=false,flag5=false;
	char *sName,*sType,*sStatus,*command,*Uid;
	sName=(char*)malloc(MAX*sizeof(char));
	sType=(char*)malloc(MAX*sizeof(char));
	sStatus=(char*)malloc(MAX*sizeof(char));
	command=(char*)malloc(MAX*sizeof(char));
	Uid=(char*)malloc(MAX*sizeof(char));
	memset(sName,0,sizeof(sName));
	memset(sType,0,sizeof(sType));
	memset(sStatus,0,sizeof(sStatus));
	memset(command,0,sizeof(command));
	memset(Uid,0,sizeof(Uid));
	int i=0,j=0,count=0,name=0,type=0,status=0,uid=0,iUid=0;
	if(cBuffer[0]!='\n'){
			
		while(cBuffer[i] != ':'){
			if(i<strlen(cBuffer)){
				command[j++] = cBuffer[i++];
				
			}
		}
		command[i]='\0';
		i++;
		j=0;

		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
			sName[j++] = cBuffer[i++];

		sName[j]='\0';
		name=strlen(sName);
		i++;
		j=0;

		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
        	                sType[j++] = cBuffer[i++];

		
                sType[j]='\0';
		type=strlen(sType);
		i++;
		j=0;


		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
			sStatus[j++] = cBuffer[i++];

		sStatus[j]='\0';
		status=strlen(sStatus);
		j=0;
		i++;
		
		 while((cBuffer[i] != '\0') && (i<strlen(cBuffer)))
                        Uid[j++] = cBuffer[i++];

		uid=strlen(Uid);

		iUid=atoi(Uid);


		if((name<13) && (name>0))
			flag1=true;
		else
			printf("\n Service name should be maximum of 12 characters\n");	
		
		if((type<13) && (type>0))
			flag2=true;
		else
			printf("\n Service type should be maximum of 12 characters\n");	
		
		if((status<13) && (status>0))
			flag3=true;
		else
			printf("\n Service status should be maximum of 12 characters\n");

		if(uid==5)
			flag4=true;
		else
			printf("\n UID must be 4 digits\n");	
		
		if(iUid==reg_uid)
			flag5=true;
		else
			printf("\n Please enter your registered UID");
		
		if((flag1==true) && (flag2==true) && (flag3==true) && (flag4==true) && (flag5==true))
			return 1;
		else
			return 0;
	}
}
