#include "sender.h"
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
    printf("client port%d, ip %s, server port %d\n");
     pthread_cond_t KToSend  = PTHREAD_COND_INITIALIZER;
 pthread_mutex_t LockSender = PTHREAD_MUTEX_INITIALIZER;
    List* input_list = List_create(); 
    printf("starting\n");
    Keyboard_init(input_list , &KToSend , &LockSender);
    Sender_init(input_list , &KToSend , &LockSender , IP_ADDRESS , SERVER_PORT);
     Sender_shutdown();
     Keyboard_shutdown();
    return 0;
}