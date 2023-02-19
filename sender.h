#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#ifndef _sender.h


#define PORT 8080
#define MAX_LEN 1024



// Function to init the Socket for() 
 
// Desc : 

// Creates and new socket with the given socket socket adress 
// Establishes the connection to this port 


int init_socket_client();




//  Desc 
// Send the message to the given socket 
int send_message(int socketDescriptor , char* message);




#endif