#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include "cpfapi.h"

struct Uim{
	int iUid;
	char cName[100];
	char cMailid[100];
};
int iUid=1000,k=0;
int uim_reg_usr( char *cBuffer ){
	FILE *fp;
	struct Uim uim[100];
	//int k;
	//uim=(struct Uim *)malloc(1*sizeof(struct Uim));
	iUid++;
	uim[k].iUid=iUid;
	bool flag1 = true,flag2 = true;
	int i = 0,j = 0;
	int count=0;	

	if(strlen(cBuffer)!=0){
		while(cBuffer[i] != ',')
			uim[k].cName[i++] = cBuffer[i];

	uim[k].cName[i]='\0';
	i++;
	printf("\ncName =>%s",uim[k].cName);

	while(cBuffer[i] != '\0')
		uim[k].cMailid[j++] = cBuffer[i++];

	uim[k].cMailid[j]='\0';
	printf("\ncMailid =>%s",uim[k].cMailid);

		if(strlen(uim[k].cName)!=0){
			for(i=0;uim[k].cName[i]!='\0';i++){
				if(isalpha(uim[k].cName[i]) || uim[k].cName[i]==' '){
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
		if(strlen(uim[k].cMailid)!=0){
			for(i=0;uim[k].cMailid[i]!='\0';i++){
				if(uim[k].cMailid[i]=='@'){
					j=i;
					count++;
				}
			if(uim[k].cMailid[i]=='.' && i>(j+2) && count==1){
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
				if(isalnum(uim[k].cMailid[i]) || uim[k].cMailid[i]=='-' || uim[k].cMailid[i]=='_' || uim[k].cMailid[i]=='.')
					continue;
				else{
					flag2=false;
				}
			}
			printf("\nMail id validation phase-1 result = (%d)\n", flag2);
			for(i=j+1;uim[k].cMailid[i]!='.';i++){
				if(isalpha(uim[k].cMailid[i]))
					continue;
				else
					flag2=false;
			}
			printf("Mail id validation phase-2 result = (%d)\n", flag2);
			i++;

		
			  for(;uim[k].cMailid[i]!='\0';i++){
				printf("\n mail id[i] :%c ,%d ",uim[k].cMailid[i],uim[k].cMailid[i]);
				
				if(isalpha(uim[k].cMailid[i])||(uim[k].cMailid[i]=='\n'))
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
		//uim[k].iUid =uim[k].iUid+1;
		
		fprintf(fp,"%d %s %s\n",uim[k].iUid,uim[k].cName,uim[k].cMailid);
		fclose(fp);
		printf("\nUID IS :%d\n",uim[k].iUid);
		return uim[k].iUid;
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
k++;
}


