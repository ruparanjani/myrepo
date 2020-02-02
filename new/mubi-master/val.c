#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
int main(){

	bool flag1 = false;
	int i = 0,j = 0;
	char cName[100],cMailid[100],cBuffer[100],command[100];
	gets(cBuffer);
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

      /*  if(status==0)
		   printf("\n matches");
        else
		   printf("\n not matching");*/

}
