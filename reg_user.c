#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include "cpfapi.h"

int iUid=1000;
int uim_reg_usr( char *cBuffer ){
	FILE *fp;
	bool flag1 = true,flag2 = true;
	int i = 0,j = 0;
	int count=0;
	char cName[100],cMailid[100];	

	if(strlen(cBuffer)!=0){
		while(cBuffer[i] != ',')
			cName[i++] = cBuffer[i];

	cName[i]='\0';
	i++;
	printf("\ncName =>%s",cName);

	while(cBuffer[i] != '\0')
		cMailid[j++] = cBuffer[i++];

	cMailid[j]='\0';
	printf("\ncMailid =>%s",cMailid);

		if(strlen(cName)!=0){
			for(i=0;cName[i]!='\0';i++){
				if(isalpha(cName[i]) || cName[i]==' '){
					continue;
				}
				else{
					flag1=false;
					break;
				}
			}
		}
		else{
			flag1=false;
		}
		if(strlen(cMailid)!=0){
			for(i=0;cMailid[i]!='\0';i++){
				if(cMailid[i]=='@'){
					j=i;
					count++;
				}
			if(cMailid[i]=='.' && i>(j+2) && count==1){
				count++;
			} 
			}
			printf("\n checking @ and .");
		if(count>2){
			printf("\n count >2 ");
			flag2=false;
		}	
		else{
			for(i=0;i<j;i++){
				if(isalnum(cMailid[i]) || cMailid[i]=='-' || cMailid[i]=='_' || cMailid[i]=='.')
					continue;
				else{
					flag2=false;
				}
			}
			printf("\nMail id validation phase-1 result = (%d)\n", flag2);
			for(i=j+1;cMailid[i]!='.';i++){
				if(isalpha(cMailid[i]))
					continue;
				else
					flag2=false;
			}
			printf("Mail id validation phase-2 result = (%d)\n", flag2);
			i++;

		
			  for(;cMailid[i]!='\0';i++){
				printf("\n mail id[i] :%c ,%d ",cMailid[i],cMailid[i]);
				
				if(isalpha(cMailid[i])||(cMailid[i]=='\n'))
					continue;
				else{
					flag2=false;
					break;
				}	
			}	
			printf("Mail id validation phase-3 result = (%d)\n", flag2);
		}
	}
	else{
		flag2=false;
	}
	if(flag1 == true && flag2 == true ){
		fp = fopen("uid_table.csv","a+");
		if (fp == NULL){
			printf("Can't open a file");
			exit(0);
		}
		fprintf(fp,"%d %s %s\n",++iUid,cName,cMailid);
		fclose(fp);
		printf("\nUID IS :%d\n", iUid);
		return iUid;
			
		}
	else if(flag1 != true&& flag2 != true){
		printf("\nInvalid name and mailid\n");
		return -1;
	}
	else if(flag1 != true){
		printf("\nInvalid name\n");
		return -1;
	}
	else{
		printf("Invalid mailid\n");
		return -1;
	}
	}
	else{
		printf("Invalid name and mailid\n");
		return -1;
	}

}


