#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include "cpfapi.h"
#define MAX 100
struct Svc_mgr{
	char *svc_mgr[3];
	int iSid;
};
int iSid=2000 ,j=0;
bool validate(char *);
int svc_reg( char *cBuffer , int iUid ){
	bool checj=false;
	FILE *fp;
	struct Svc_mgr svc[100];
	int i = 0,l=0;
	int count = 0;
	char *str;
	iSid++;
	svc[j++].iSid=iSid;
	
	if(strlen(cBuffer) && cBuffer!=NULL && cBuffer[0]!=" "){
		do
		{	
			if(i==0)
				str = strtok(cBuffer, ",");
			else
				str = strtok(NULL, ",");
			if(strlen(str)!=0){
				int count = 0;
			for(int i=0;str[i]!='\0';i++){
				if(isalpha(str[i]) ||  (str[i]==' ' && i!=0 && ++count && count <= 1))
					continue;
				}
				svc[j].svc_mgr[i]=(char*)malloc(150*sizeof(char));
				strcpy(svc[j].svc_mgr[i],str);
				//printf("svc_mgr[%d] = %s\n",i,svc_mgr[i]);
				i++;
			}
			else
				break;
		}while(str != NULL && i <= 2 );
		
		svc[j].svc_mgr[2][strlen(svc[j].svc_mgr[2])-1]='\0';
		fp = fopen("service_reg_table.csv","a+");
		if (fp == NULL){
			printf("Can't open a file");
			exit(0);
		}
		fprintf(fp,"%d,%s,%s,%s,%d\n",iUid,svc[j].svc_mgr[0],svc[j].svc_mgr[1],svc[j].svc_mgr[2],svc[j].iSid);
		fclose(fp);
		for(i=0;i<=2;i++){
			free(svc[j].svc_mgr[i]);
			svc[j].svc_mgr[i]=NULL;
		}
		memset(&cBuffer,0,sizeof(cBuffer));
		return svc[j].iSid;
		//j++;
	}
}
/*bool validate(char *str)
{char cSvc_name[100],cSvc_type[100],cSvc_status[100];
	if(cBuffer!=NULL && cBuffer[0]!=" "){
		while(cBuffer[i] != ',')
			cSvc_name[i++] = cBuffer[i];
		cSvc_name[i]='\0';
		i++;
                while(cBuffer[i] != ',')
			cSvc_type[j++] = cBuffer[i++];
		cSvc_name[j]='\0';
		i++;
		while(cBuffer[i] != '\0')
			cSvc_status[j++] = cBuffer[i++];
		cSvc_status[j]='\0';
	int count = 0;
	for(int i=0;str[i]!='\0';i++){
		if(isalpha(str[i]) ||  (str[i]==' ' && i!=0 && ++count && count <= 1))
			continue;
		else
			return false;
		}
	return true;
}*/
//(str[i] == '\n' && i == strlen(str)-1) ||
//else
			//return false;
				/*if(!validate(str)){
					printf("It's failed");
					//return svc_reg(cBuffer,iUid);
				}*/
/*char cSvc_name[100],cSvc_type[100],cSvc_status[100];
	if(cBuffer!=NULL && cBuffer[0]!=" "){
		while(cBuffer[i] != ',')
			cSvc_name[i++] = cBuffer[i];
		cSvc_name[i]='\0';
		i++;
                while(cBuffer[i] != ',')
			cSvc_type[j++] = cBuffer[i++];
		cSvc_name[j]='\0';
		i++;
		while(cBuffer[i] != '\0')
			cSvc_status[j++] = cBuffer[i++];
		cSvc_status[j]='\0';*/
