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
#define max 255

int client()
{

	int sock_fd=0,msg_len=0,val=0,uid=0,ibuffer=0;
	struct sockaddr_in servaddr;
	char buffer[max];
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
        printf("\nSocket created");
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(server_ip);
	servaddr.sin_port=htons(PORT);
	connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	memset(buffer, 0, sizeof(buffer));
	msg_len=recv(sock_fd,buffer,max,0);	
        printf("\n%s\n",buffer);
	while(1){
		memset(&buffer,0,sizeof(buffer));
		fgets(buffer,max,stdin);
		if(buffer[0]=='!'){
			break;
		}
		else{
			val=main_validation(buffer,uid);
			if(val==1){
				send(sock_fd,buffer,max,0);
				memset(&buffer,0,sizeof(buffer));
				msg_len=recv(sock_fd,buffer,max,0);
				ibuffer=atoi(buffer);
				if((ibuffer>=1001) && (ibuffer<=3000))
					uid=ibuffer;
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
