#include "receiver.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define PORT 6969
#define MAX_LEN 1024
#define ID_ADDR "127.0.0.1"
static int sock;
void init_socket()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(PORT);
    int socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

    bind(socketDescriptor, (struct sockaddr* ) &sin, sizeof(sin));
    sock = socketDescriptor;
}

void* listen(void* pt, int sock)
{
    while(1)
    {
        struct sockaddr_in sinRemote;
        unsigned int sin_len = sizeof(sinRemote);
        char messageRx[MAX_LEN];
        int bytesRx = recvfrom(sock, messageRx, MAX_LEN, 0, (struct sockaddr*) &sinRemote, &sin_len);
        
        int terminateIdx = (bytesRx < MAX_LEN) ? bytesRx : MAX_LEN -1;
        printf("Message received (%d): \n%s \n", bytesRx, messageRx);

        //int incMe = atoi(messageRx);

        
    }
}

int main()
{
    init_socket();
    listen(NULL, sock);
    
}