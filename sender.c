#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#define PORT 6969
#define MAX_LEN 1024
// Socket address 





int init_sokcet_connect(){ 
 
}

int main(){
       // create the socket addresss 
    struct sockaddr_in sin; 
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET; 
    sin.sin_port = htons(PORT);

   int  sock; 
    sock = socket(AF_INET , SOCK_STREAM , 0 ) ;
   if(sock == -1){printf("Failed");
        return -1 ;
   }

    char* message = "test";
    if ((connect(sock, (struct sockaddr_in*)&sin,sizeof(sin)))< 0){return -1;  }
    printf("conncected");
   return sock ;
	if( send(sock , message , strlen(message) , 0) < 0)
	{
		printf("Send failed");
		return 1;
	}
	printf("Data Send\n");
	
	return 0;
}
