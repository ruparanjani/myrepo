#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include <regex.h>
#include<ctype.h>
#include<stdbool.h>
#include "validation.h"
#define PORT 2020
#define server_ip "127.0.0.1"
#define max 100

int client()
{

	int sock_fd=0,msg_len=0,val=0;
	struct sockaddr_in servaddr;
	char buffer[max],*buffer1;
	buffer1=(char*)malloc(4*sizeof(char));
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
        printf("\nSocket created");
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(server_ip);
	servaddr.sin_port=htons(PORT);
	connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	memset(buffer, 0, sizeof(buffer));
	msg_len=recv(sock_fd,buffer,max,0);	
        printf("%s\n",buffer);
	while(1){
		memset(&buffer,0,sizeof(buffer));
		fgets(buffer,max,stdin);
		if(buffer[0]=='!'){
			break;
		}
		else{
		val=main_validation(buffer);
		if(val==1){
			send(sock_fd,buffer,max,0);
			memset(&buffer,0,sizeof(buffer));
			msg_len=recv(sock_fd,buffer,max,0);
			id_validation(buffer);
		}
		}
	}
	close(sock_fd);
	return 0;
}
void main()
{
	client();
}
