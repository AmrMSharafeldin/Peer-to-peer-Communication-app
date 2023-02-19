
#include "sender.h"

// Function to init the Socket for() 
 
// Desc : 

// Creates and new socket with the given socket socket adress 
// Establishes the connection to this port 


int init_socket_client(){

     struct sockaddr_in socket_adress; 
   socket_adress.sin_addr.s_addr = htonl(INADDR_ANY);
   socket_adress.sin_family = AF_INET; 
   socket_adress.sin_port = htons(PORT);

   int  socketDescriptor; 
   socketDescriptor = socket(PF_INET , SOCK_DGRAM , 0 ) ;

   if (socketDescriptor < 0){
       printf("socket field\n");
       return -1;
       }
    if ((connect(socketDescriptor, (struct sockaddr*)&socket_adress,sizeof(socket_adress))) < 0){
        printf("conncection field\n");
        return -1; 
    }
    printf("new socket created and conncection established\n");
   return socketDescriptor;
}




//  Desc 
// Send the message to the given socket 
int send_message(int socketDescriptor , char* message){
    if (strlen(message) > MAX_LEN){printf("Message exceedes the max buffer size \n"); return -1;}
    send(socketDescriptor , message , strlen(message) , 0);
}

