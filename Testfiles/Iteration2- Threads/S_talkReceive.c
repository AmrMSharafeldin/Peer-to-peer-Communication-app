#include "receiver.h"
#include "screen.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "list.h"


int main(int argc, char* argv[]){
   
    if(argc != 4)
    {
        printf("the number of arguments is incorrect");
        return 0;
    }
    short CLIENT_PORT = atoi(argv[1]);
    char* IP_ADDRESS = argv[2];
    short SERVER_PORT = atoi(argv[3]);
    printf("client port %d, server port %d", CLIENT_PORT, SERVER_PORT);
    List* input_list = List_create(); 
    pthread_cond_t KToReceive  = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t LockReceiver = PTHREAD_MUTEX_INITIALIZER;
    printf("starting\n");
    Screen_init(input_list , &KToReceive , &LockReceiver);
    Receiver_init(input_list,&KToReceive , &LockReceiver, CLIENT_PORT);
    Screen_shutdown();
    Receiver_shutdown();
    return 0;
}