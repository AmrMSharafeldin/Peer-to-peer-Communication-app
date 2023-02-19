#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#define PORT 8080
#define MAX_LEN 1024
// Socket address 


int main(){
       // create the socket addresss 
   struct sockaddr_in sin; 
   sin.sin_addr.s_addr = htonl("127.0.0.1");
   sin.sin_family = AF_INET; 
   sin.sin_port = htons(PORT);

   int  sock; 
   sock = socket(AF_INET , SOCK_STREAM , 0 ) ;
   char* message = "test";
   connect(sock, (struct sockaddr_in*)&sin,sizeof(sin)) ;
   send(sock , message , strlen(message) , 0);


	
	return 0;
}
