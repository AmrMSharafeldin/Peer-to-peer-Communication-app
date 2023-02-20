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
    printf("starting\n");
    Screen_init(input_list);
    Receiver_init(input_list);
     Screen_shutdown();
     Receiver_shutdown();
    return 0;
}