#include <stdio.h>
#include <regex.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
 
int main()
{
    char* str;char* buffer;char* buffer1;
    int f1=0,f2=0,f3=0,i=0,j=0,len=0;
    bool flag2=false,flag3=false;
	bool flag1 = false;
	char cName[100],cMailid[100],cBuffer[100],command[100];
	void validate_buffer(char []);
    str=(char*)malloc(100*sizeof(char));
    buffer=(char*)malloc(100*sizeof(char));
    buffer1=(char*)malloc(100*sizeof(char));
    gets(str);
	len=strlen(str);
	str[len]='\0';
    const char* pattern = "[A-Z_]+:[a-zA-Z]+,[a-zA-Z0-9_-].+@[a-z]+.com";
   
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;
    int status = regexec(&re, str, 0, NULL, 0);
    regfree(&re);
	for(i=0;i<=len;i++)
		printf("\n data %c,%d",str[i],str[i]);
    printf("\n status %d",status);
    //if(status ==1)flag1;
   if (status == 0) {
        //flag1=true;
        printf("\n%s matching",str);
    }
	
    else{
		validate_buffer(str);         	
}
}
void validate_buffer(char cBuffer[100]){
	bool flag1 = false;
	char cName[100],cMailid[100],command[100];
	int i=0,j=0;
	printf("cbuffer=%s",cBuffer);
	if(cBuffer[0]!='\n'){

		while(cBuffer[i] != ':'){
			command[i] = cBuffer[i];
			i++;
		}

		command[i]='\0';
		printf("\n command=%s",command);
		i++;

		while(cBuffer[i] != ',')
			cName[j++] = cBuffer[i++];

		cName[j]='\0';
		i++;
		printf("\ncName =>%s",cName);
		j=0;

		while(cBuffer[i] != '\0')
			cMailid[j++] = cBuffer[i++];

		cMailid[j]='\0';
		printf("\ncMailid =>%s",cMailid);

		if(strlen(command)!=0){
			command_validation(command);

		}


		if(strlen(cName)!=0){
			for(i=0;cName[i]!='\0';i++){
				if(isalpha(cName[i]) || cName[i]==' '){
					continue;
				}
				else{
					flag1=true;
					break;
				}
			}
		}

		if(flag1==true)
			printf("\nname invalid");
		else
			printf("\n mailid invalid");


	}


    }

void command_validation(char str[100])
{
	int status=0,i=0,jee=0;
	int len=strlen(str);
	
   	for(i=0;i<len;i++){
		    if (isupper(str[i]) || (str[i]=='_')){
			jee++;
		    }

		    else
			   status++;
			        
        }

        if(status>0)
		   printf("\n command invalid");
      /*  else
		   printf("\n not matching");*/

}
