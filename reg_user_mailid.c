#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include "cpfapi.h"

int iUid=1000;
int count=0;
int uim_reg_usr( char *cBuffer ){
	FILE *fp;
	bool flag1 = true,flag2 = true;
	int i = 0,j = 0;
	char cName[100],cMailid[100],cfBuffer[256],*str;	
	if(strlen(cBuffer)!=0){
	while(cBuffer[i] != ',')
		cName[i++] = cBuffer[i];
	cName[i]='\0';
	i++;
	while(cBuffer[i] != '\0')
		cMailid[j++] = cBuffer[i++];
	cMailid[j]='\0';
	if(strlen(cName)!=0){
		for(i=0;cName[i]!='\0';i++){
			if(isalpha(cName[i]) || (cName[i]==' ' && i!=0)){
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
	count=0;
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
		if(count>2){
                	printf("%c",cMailid[i]);
			flag2=false;
		}	
		else{
			
			for(i=0;i<j;i++){
				if(isalnum(cMailid[i]) || ((cMailid[i]=='-' || cMailid[i]=='_' || cMailid[i]=='.' || cMailid[i]==' ') && i!=0))
					continue;
				else{
					flag2=false;
					break;
				}
			}
			for(i=j+1;(cMailid[i]!='.' && flag2);i++){
				if(isalpha(cMailid[i]))
					continue;
				else{
					flag2=false;
				}
			}
			i++;
			for(;(cMailid[i]!='\0' && flag2);i++){
				if(isalpha(cMailid[i]))
					continue;
				else{
					flag2=false;
				}	
			}	
		}
	}
	else{
		flag2=false;
	}
	
	if(flag1 && flag2){
		flag2=false;
		fp = fopen("uid_table.csv","r+");
		while(EOF != fscanf(fp, "%[^\n]\n", cfBuffer)){
			if (strstr(cfBuffer,cMailid)){
				flag2=true;
				str = strtok(cfBuffer, ",");
		        	printf("Data from the file: %s\n",str);
				break;
			}
		}
		fclose(fp);
		if(!flag2){
			fp = fopen("uid_table.csv","a+");
			if (fp == NULL){
				printf("Can't open a file");
				exit(0);
			}
			fprintf(fp,"%d %s %s\n",++iUid,cName,cMailid);
			fclose(fp);
			return iUid;
		}
		return str-'0';
	}
	else if(!flag1 && !flag2)
		printf("\nInvalid name and mailid\n");
	else if(!flag1)
		printf("\nInvalid name\n");
	else if(!flag2)
		printf("Invalid mailid\n");
	}
	else{
		printf("Invalid name and mailid\n");
	}

}

/*void main()
{
	char *str;
	str=(char*)malloc(100*sizeof(char));
	do{
		printf("enter name,mailid\n");
		gets(str);
		uim_reg_usr(str); 
	}while(1);
}*/
