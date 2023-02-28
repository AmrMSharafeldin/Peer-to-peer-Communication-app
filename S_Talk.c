#include "sender.h"
#include "keyboard.h"
#include "screen.h"
#include "receiver.h"
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
   printf("client port %d, server port %d\n", CLIENT_PORT, SERVER_PORT);
   List* input_list = List_create(); 
      List* display_list = List_create(); 
    pthread_cond_t KToSender  = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t LockSender = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t KToReceiver  = PTHREAD_COND_INITIALIZER;
    pthread_mutex_t LockReceiver = PTHREAD_MUTEX_INITIALIZER;
    printf("starting\n");
    Sender_init(input_list , &KToSender , &LockSender , IP_ADDRESS , SERVER_PORT);
    Keyboard_init(input_list,&KToSender , &LockSender);
    Receiver_init(display_list , &KToReceiver , &LockReceiver  , CLIENT_PORT, IP_ADDRESS);
    Screen_init(display_list,&KToReceiver , &LockReceiver);
    Sender_shutdown();
    Keyboard_shutdown();
    Receiver_shutdown();
    Screen_shutdown();
    return 0;
}
