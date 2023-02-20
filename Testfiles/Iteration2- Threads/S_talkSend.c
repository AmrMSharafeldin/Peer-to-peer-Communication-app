#include "sender.h"
#include "keyboard.h"
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
    Keyboard_init(input_list);
    Sender_init(input_list);
     Sender_shutdown();
     Keyboard_shutdown();
    return 0;
}