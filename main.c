#include "receiver.h"
#include "sender.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
pthread_mutex_t lock;
static List aList;
int main(int argc, char* argv[])
{
   if(argc != 3)
    {
        printf("the number of arguments is incorrect");
        return 0;
    }
    short CLIENT_PORT = atoi(argv[0]);
    char* IP_ADDRESS = argv[1];
    short SERVER_PORT = atoi(argv[2]);
    List* input_list = List_create(); 
    
}
