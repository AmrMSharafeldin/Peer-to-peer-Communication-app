#include "receiver.h"
#include "list.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
static short CLIENT_PORT;
#define MAX_LEN 1024
static pthread_t receiver_thread;
static pthread_cond_t* Receiver_Cond ;
static pthread_mutex_t* Receiver_Lock;
//initialize the socket and bind it to specific port
//
static int FileDescriptor;
static char* IP_ADDR;
int init_socket_receiver()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(CLIENT_PORT);
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
    FileDescriptor = socketDescriptor;
    return socketDescriptor;
}
//listening body, contains the critical section problem

void lis(int sock, void* Receive_List)
{struct sockaddr_in sinRemote;

    if(sock == -1)
        return;
    List* Shared = (List*)Receive_List;
    while (1)
    {

        unsigned int sin_len = sizeof(sinRemote);
        char* messageRx = malloc(MAX_LEN); // Modified this part so that the buffer is dynamically allocated 
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
    return 0;
}
//thread initializer // public method
void* Receiver_init(void* Receive_List , pthread_cond_t* Cond , pthread_mutex_t* Lock, short client, char* IP)
{   Receiver_Cond = Cond; 
    Receiver_Lock = Lock;
    CLIENT_PORT = client;
    IP_ADDR = IP;

    pthread_create(&receiver_thread, NULL, listenThread, Receive_List);
    return 0;
}
//thread destructor // public method 
void* Receiver_shutdown(void)
{
    pthread_join(receiver_thread, NULL);
    return 0;
}

void Cancel_Receiver(){
    pthread_cancel(receiver_thread);
    close(FileDescriptor);
}