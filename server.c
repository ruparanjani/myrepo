#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include "cpfapi.h"
#define PORT 2027
#define MAX 255

void *client_thread ( void *arg )               //thread function
{
        int msg_len,i;
        int newsock_fd=(int)arg;
        char *buffer1,buffer[]="Register user [REG_USR:name,mailid] or Existing user [UID]";
        
	buffer1=(char*)malloc(150*sizeof(char));
	write(newsock_fd, buffer, sizeof(buffer));
        memset(&buffer,0,sizeof(buffer));

        while(1){
		memset(&buffer,0,sizeof(buffer));
		read(newsock_fd, buffer, sizeof(buffer));
                i=strlen(buffer);
		buffer[i]='\0';
		buffer1=User_Validation(buffer); 
		write(newsock_fd, buffer1, sizeof(buffer1));


        }
        close(newsock_fd);
}

int server()
{
        int sock_fd,newsock_fd,cliaddrlen,bind_check,lis_check;
        struct sockaddr_in servaddr,cliaddr;
        pthread_t serverThread;
        sock_fd=socket(AF_INET,SOCK_STREAM,0);

        if(sock_fd<0)
                printf("\nSocket not created");
       
        printf("\nSocket created");
        memset(&servaddr,0,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(PORT);
        bind_check=bind(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));

        if(bind_check<0)
		printf("\nSocket not binded");
       
        printf("\nBinding");
        lis_check=listen(sock_fd,5);

        if(lis_check<0)
                printf("\nListening failed");
   
        printf("\nlistening");

        while(1){
                printf("\nSERVER WAITING FOR NEW CONNECTION\n");
                cliaddrlen=sizeof(cliaddr);
                newsock_fd=accept(sock_fd,(struct sockaddr*)&cliaddr,&cliaddrlen);

                if(newsock_fd<0)
                        printf("\nClient not connected");
             
                printf("CONNECTED TO CLIENT\n");
                pthread_create(&serverThread,NULL,&client_thread,(void *)newsock_fd);
        }
return 0;
}


void main(){

	server();
}

