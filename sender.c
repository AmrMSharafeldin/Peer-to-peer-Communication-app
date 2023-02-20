
#include "sender.h"

#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "list.h"


// Function to init the Socket for() 
 
// Desc : 

// Creates and new socket with the given socket socket adress 
// Establishes the connection to this port 

static pthread_t sender_thread;

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



// Desc 
// Creates the socket and send messages to the port on user input 

void* S_send(void* Send_list){

    // Create the socket 
    int socket_Descriptor = init_socket_client();
    // Ask the user for input 
    
    
    // printf("Please enter the message\n");

    // Create the buffer  // To do just pop from the shared list 
    // A critical section problem
    // Each S_talk will have to static list heads 
    // The first one is shared between the Screen and Receive thread
    // The second is shared between the Sender and keyboard 

    //***** for testing purposes 

    // char* message = malloc(MAX_LEN); 
    // scanf("%s" , message);
    // send_message(socket_Descriptor , message);
    // fflush(stdin);
    // fflush(stdout);
    // free(message);
    // *****************************
    List* Shared = (List*)Send_list;

    char* message = List_trim(Shared); //   Critical Section 
    send_message(socket_Descriptor , message);
    fflush(stdin);
    fflush(stdout);         
    free(message);
    printf("message is sent\n");
    pthread_cancel(sender_thread);
}






// Desc 
// Thread init 

void* Sender_init(void* unused){

    pthread_create(&sender_thread, NULL , S_send , unused );

}

// Desc 
// Thread shutdown
void* Sender_shutdown(void){


    // Cancel
    //pthread_cancel(sender_thread);


    // Join 

    pthread_join(sender_thread , NULL);
}
