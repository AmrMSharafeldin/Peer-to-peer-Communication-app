// #include "receiver.h"
// #include "list.h"
// #include <pthread.h>
// #include <stdio.h>
// #include <netdb.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #define PORT 8080
// #define MAX_LEN 1024
// static pthread_t receiver_thread;
// //initialize the socket and bind it to specific port
// //
// int init_socket_receiver()
// {

//     memset(&sin, 0, sizeof(sin));
//     sin.sin_family = AF_INET;
//     sin.sin_addr.s_addr = htonl(INADDR_ANY);
//     sin.sin_port = htons(PORT);
//     int socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);
//     if (socketDescriptor < 0){
//         printf("socket connection failed\n");
//         return -1;
//     }

//     if((bind(socketDescriptor, (struct sockaddr *)&sin, sizeof(sin))<0))
//     {
//         printf("bind failed\n");
//         return -1;
//     }
//     return socketDescriptor;
// }
// //listening body, contains the critical section problem

// void lis(int sock, void* Receive_List)
// {
//     if(sock == -1)
//         return 0;
//     List* Shared = (List*)Receive_List;
//     while (1)
//     {

//         unsigned int sin_len = sizeof(sinRemote);
//         char messageRx[MAX_LEN];
//         int bytesRx = recvfrom(sock, messageRx, MAX_LEN, 0, (struct sockaddr *)&sinRemote, &sin_len);

//         int terminateIdx = (bytesRx < MAX_LEN) ? bytesRx : MAX_LEN - 1;
//         messageRx[terminateIdx] = 0;

//         if(List_append(Shared, messageRx)<0)
//         {
//             printf("the list append has failed\n");
//         }
//         //printf("Message received (%d): \n%s \n", bytesRx, messageRx); // To Do // Remvoe this line because it's not necessery 
//     }
// }
// //thread wrapper to run subroutines
// //call subroutines 
// void *listenThread(void *Receive_List)
// {
//     int desc = init_socket_receiver();
//     lis(desc, Receive_List);
// }
// //thread initializer // public method
// void* Receiver_init(void* Receive_List)
// {
//     pthread_create(&receiver_thread, NULL, listenThread, Receive_List);
// }
// //thread destructor // public method 
// void* Receiver_shutdown(void)
// {
//     pthread_join(receiver_thread, NULL);
// }
#include "receiver.h"
#include "list.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define PORT 8080
#define MAX_LEN 1024
static pthread_t receiver_thread;
static pthread_cond_t* Receiver_Cond ;
static pthread_mutex_t* Receiver_Lock;
//initialize the socket and bind it to specific port
//

int init_socket_receiver()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(PORT);
    int socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);
    if (socketDescriptor < 0){
        printf("socket connection failed\n");
        return -1;
    }

    if((bind(socketDescriptor, (struct sockaddr *)&sin, sizeof(sin))<0))
    {
        printf("bind failed\n");
        return -1;
    }
    return socketDescriptor;
}
//listening body, contains the critical section problem

void lis(int sock, void* Receive_List)
{struct sockaddr_in sinRemote;

    if(sock == -1)
        return 0;
    List* Shared = (List*)Receive_List;
    while (1)
    {

        unsigned int sin_len = sizeof(sinRemote);
        char messageRx[MAX_LEN];
        int bytesRx = recvfrom(sock, messageRx, MAX_LEN, 0, (struct sockaddr *)&sinRemote, &sin_len);

        int terminateIdx = (bytesRx < MAX_LEN) ? bytesRx : MAX_LEN - 1;
        messageRx[terminateIdx] = 0;
        //printf("Message received (%d): \n%s \n", bytesRx, messageRx);
        
        //mutex lock
        pthread_mutex_lock(Receiver_Lock);
        {
            List_prepend(Shared, messageRx);
        }
        pthread_mutex_unlock(Receiver_Lock);
        pthread_cond_signal(Receiver_Cond);
        

        //mutex unlock
        //printf("Message received (%d): \n%s \n", bytesRx, messageRx); // To Do // Remove this line because it's not necessery 
    }
}
//thread wrapper to run subroutines
//call subroutines 
void *listenThread(void *Receive_List)
{
    int desc = init_socket_receiver();
    lis(desc, Receive_List);
}
//thread initializer // public method
void* Receiver_init(void* Receive_List , pthread_cond_t* Cond , pthread_mutex_t* Lock)
{   Receiver_Cond = Cond; 
    Receiver_Lock = Lock;
    pthread_create(&receiver_thread, NULL, listenThread, Receive_List);
}
//thread destructor // public method 
void* Receiver_shutdown(void)
{
    pthread_join(receiver_thread, NULL);
}