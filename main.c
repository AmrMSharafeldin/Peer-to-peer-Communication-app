#include "receiver.h"
#include "sender.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int a;

    pthread_t list;
    pthread_create(&list, NULL, listenThread, NULL);
    killListenThread();
    pthread_join(list, NULL);

}