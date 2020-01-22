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
int iSid=3000,j=-1;
int svc_reg( char *cBuffer){
	bool check=false;
	FILE *fp;
	struct Svc_mgr svc[100];
	int i = 0,l=0;
	int count = 0,rv=0;
	char *str;
	printf("before sid_retrive");
	iSid=sid_retrive();
	//++iSid;
	//printf("rv => %d",rv);
	svc[++j].iSid=iSid;
	//pintf("svc[++j].iSid =>%d",svc[++j].iSid);
	if(strlen(cBuffer) && cBuffer!=NULL && cBuffer[0]!=" "){
		do
		{	
			if(i==0)
				str = strtok(cBuffer, ",");
			else
				str = strtok(NULL, ",");
			if(strlen(str)!=0){
				int count = 0;
				svc[j].svc_mgr[i]=(struct Svc_mgr*)malloc(1*sizeof(struct Svc_mgr));
				strcpy(svc[j].svc_mgr[i],str);
				i++;
			}
			else
				break;
		}while(str != NULL && i <= 3 );
		
		svc[j].svc_mgr[3][strlen(svc[j].svc_mgr[3])-1]='\0';
		fp = fopen("service_reg_table.csv","a+");
		if (fp == NULL){
			printf("Can't open a file");
			exit(0);
		}
		//iSid=sid_retrive();
		fprintf(fp,"%d,%s,%s,%s,%s\n",++iSid,svc[j].svc_mgr[0],svc[j].svc_mgr[1],svc[j].svc_mgr[2],svc[j].svc_mgr[3]);
		fclose(fp);
		for(i=0;i<=3;i++){
			free(svc[j].svc_mgr[i]);
			svc[j].svc_mgr[i]=NULL;
		}
		memset(&cBuffer,0,sizeof(cBuffer));
		return iSid;
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
