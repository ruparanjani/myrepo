#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include "cpfapi.h"
#define PORT 2027
#define server_ip "127.0.0.1"
#define max 100

int client()
{

	int sock_fd=0,msg_len=0;
	struct sockaddr_in servaddr;
	char buffer[max],*buffer1;
	buffer1=(char*)malloc(4*sizeof(char));
//	int buff;
	//printf("hello");
	sock_fd=socket(AF_INET,SOCK_STREAM,0);
        printf("\nSocket created");
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(server_ip);
	servaddr.sin_port=htons(PORT);
	connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	msg_len=recv(sock_fd,buffer,max,0);	
        printf("%s\n",buffer);
	while(1){
		//msg_len=recv(sock_fd,buffer,max,0);	
                //printf("%s\n",buffer);
		//id_validation(buffer);
		memset(&buffer,0,sizeof(buffer));
		fgets(buffer,max,stdin);
		if(buffer[0]=='!'){
			break;
		}
		else{
		send(sock_fd,buffer,max,0);
		memset(&buffer,0,sizeof(buffer));
		msg_len=recv(sock_fd,buffer,max,0);
		id_validation(buffer);
		//printf("%s\n",buffer);
		}
//		msg_len=recv(sock_fd,buffer1,max,0);
  //		printf("%s",buffer1);
		//              printf("%d\n",buff);
	}
	close(sock_fd);
	return 0;
}
void main()
{
	client();
}
