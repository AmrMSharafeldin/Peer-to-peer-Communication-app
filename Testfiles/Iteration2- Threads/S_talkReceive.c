#include "receiver.h"
#include "screen.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "list.h"


int main(void* args){

     List* input_list = List_create(); 
     pthread_cond_t KToReceive  = PTHREAD_COND_INITIALIZER;
 pthread_mutex_t LockReceiver = PTHREAD_MUTEX_INITIALIZER;
    printf("starting\n");
    Screen_init(input_list , &KToReceive , &LockReceiver);
    Receiver_init(input_list,&KToReceive , &LockReceiver );
     Screen_shutdown();
     Receiver_shutdown();
    return 0;
}