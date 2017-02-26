#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include "socket.h"

static int socket_desc;
static char buffer[1024];
static int bufPtr = 0;
static int bufSize = 0;

int socketInit(){
    struct sockaddr_in server;
    //char *message , server_reply[2000];
    puts("Socket init");
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1){
        printf("Could not create socket");
		return 0;
    }
         
    server.sin_addr.s_addr = inet_addr("52.38.98.137");
    server.sin_family = AF_INET;
    server.sin_port = htons( 1099 );
 
    //Connect to remote server
    if (connect(socket_desc , (struct sockaddr *)&server , sizeof(server)) < 0){
        puts("connect error");
        return 0;
    }
	return 1;
}

int sendStr(char* message){
	if( send(socket_desc , message , strlen(message) , 0) < 0)
        return 0;
    return 1;
}

int readLine (char* lineBuffer){ // not using
	int i=0;
	while ( bufPtr < bufSize){
		if( buffer[bufPtr] == '\n'){
			lineBuffer[i] = '\0';
			bufPtr++;
			return i;
		} else 
			lineBuffer[i++] = buffer[bufPtr++];
	}
		bufSize = recv(socket_desc, buffer, 1024, 0);
		bufPtr = 0;
		return i + readLine(&lineBuffer[i]);
	
}

int recvStr(char* response){
	if( recv(socket_desc, response , 1024, 0) < 0){
        puts("recv failed");
		return 0;
	}
    puts(response);
	/*strncpy(response, server_reply, strlen(response));
	response[strlen(response) - 1] = '\0';*/
	return 1;
}






