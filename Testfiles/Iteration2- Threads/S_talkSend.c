#include "sender.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "list.h"

int main(void* args){


     pthread_cond_t KToSend  = PTHREAD_COND_INITIALIZER;
 pthread_mutex_t LockSender = PTHREAD_MUTEX_INITIALIZER;
    List* input_list = List_create(); 
    printf("starting\n");
    Keyboard_init(input_list , &KToSend , &LockSender);
    Sender_init(input_list , &KToSend , &LockSender);
     Sender_shutdown();
     Keyboard_shutdown();
    return 0;
}