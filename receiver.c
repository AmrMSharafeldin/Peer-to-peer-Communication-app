#include "receiver.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define PORT 8080
#define MAX_LEN 1024

int init_socket_receiver()
{

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(PORT);
    int socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

    bind(socketDescriptor, (struct sockaddr *)&sin, sizeof(sin));
    return socketDescriptor;
}

void lis(int sock)
{
    while (1)
    {

        unsigned int sin_len = sizeof(sinRemote);
        char messageRx[MAX_LEN];
        int bytesRx = recvfrom(sock, messageRx, MAX_LEN, 0, (struct sockaddr *)&sinRemote, &sin_len);

        int terminateIdx = (bytesRx < MAX_LEN) ? bytesRx : MAX_LEN - 1;
        messageRx[terminateIdx] = 0;
        printf("Message received (%d): \n%s \n", bytesRx, messageRx);
    }
}

void *listenThread(void *args)
{
    int desc = init_socket_receiver();
    lis(desc);
}