#include <stdio.h>
#include <regex.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
 
int  reg_svc_validation(char *str)
{
    int i=0,len=0;
    len=strlen(str);
    str[len]='\0';
   // printf("\n len=%d",len);
    const char* pattern = "[A-Z_]+:[a-zA-Z ]+,[a-zA-Z ]+,[a-zA-Z ]+,[0-9]";
    regex_t re;
	
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;

    int status = regexec(&re, str, 0, NULL, 0);
    regfree(&re);
	if(len==0)
		printf("\n no input");

	else if (status == 0) {
	       //	printf("\n%s matching",str);
		return 1;
     }
	
    else{
		svc_validate_buffer(str);         	
    }
    
}    
void svc_validate_buffer(char *cBuffer){
	bool flag1 = false,flag2=false,flag3=false,flag4=false;
	char *sName,*sType,*sStatus,*command,*Uid;
	sName=(char*)malloc(150*sizeof(char));
	sType=(char*)malloc(150*sizeof(char));
	sStatus=(char*)malloc(150*sizeof(char));
	command=(char*)malloc(150*sizeof(char));
	Uid=(char*)malloc(15*sizeof(char));
	int i=0,j=0,count=0;
	//printf("cbuffer=%s",cBuffer);
	if(cBuffer[0]!='\n'){
			
		while(cBuffer[i] != ':'){
			command[i] = cBuffer[i];
			i++;
		}

		command[i]='\0';
		//printf("\n command=%s",command);
		i++;

		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
			sName[j++] = cBuffer[i++];

		sName[j]='\0';
		i++;
		//printf("\nstype =>%s",cName);
		j=0;

		while((cBuffer[i] != ',') && (i<strlen(cBuffer)))
                        sType[j++] = cBuffer[i++];

                sType[j]='\0';
                i++;
		j=0;


		while((cBuffer[i] != '\0') && (i<strlen(cBuffer)))
			sStatus[j++] = cBuffer[i++];

		sStatus[j]='\0';
		/*printf("\nsname =>%s",sName);
		 printf("\nstype =>%s",sType);
		  printf("\nsstatus =>%s",sStatus);
		  printf("\n length of stype=%d",strlen(sType));
		   printf("\n length of sstatus=%d",strlen(sStatus));
		    printf("\n length of sname=%d",strlen(sName));*/

		
		 while((cBuffer[i] != '\0') && (i<strlen(cBuffer)))
                        Uid[j++] = cBuffer[i++];

                Uid[j]='\0';

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
			printf("\n no service name");
		}

		if(flag1==true)
			printf("\nservice name invalid");
		 
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
                        printf("\n no service type");
                }


                if(flag2==true)
                        printf("\nservice type invalid");

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
                        printf("\n no service status");
                }


                if(flag3==true)
                        printf("\nservice status invalid");

		 if(strlen(Uid)!=0){
                        for(i=0;Uid[i]!='\0';i++){
                                if(isdigit(Uid[i])){
					count++;
                                        continue;
                                }
                                else{
                                        flag1=true;
                                        break;
                                }
                        }
                }
                else{
                        printf("\n no uid");
                }

                if(flag4==true)
                        printf("\nuid invalid");
		if(count!=4)
			printf("\n uid must be 4 digit ,pls enter valid uid");


	}
     }


