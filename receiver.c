//#include "receiver.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#define PORT 8080
#define MAX_LEN 1024
#define ID_ADDR "127.0.0.1"
//static int sock;
int init_socket()
{
    // struct sockaddr_in sin;
    // memset(&sin, 0, sizeof(sin));
    // sin.sin_family = AF_INET;
    // sin.sin_addr.s_addr = htonl("127.0.0.1");
    // sin.sin_port = htons(PORT);
    // int socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

    // bind(socketDescriptor, (struct sockaddr* ) &sin, sizeof(sin));
    //return socketDescriptor;
}

void lis(int sock)
{
    // while(1)
    // {
    //     struct sockaddr_in sinRemote;
    //     unsigned int sin_len = sizeof(sinRemote);
    //     char messageRx[MAX_LEN];
    //     int bytesRx = recvfrom(sock, messageRx, MAX_LEN, 0, (struct sockaddr_in*) &sinRemote, &sin_len);
        
    //     int terminateIdx = (bytesRx < MAX_LEN) ? bytesRx : MAX_LEN -1;
    //     printf("Message received (%d): \n%s \n", bytesRx, messageRx);

    //     //int incMe = atoi(messageRx);

        
    // }
}

int main()
{
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl("127.0.0.1");
    sin.sin_port = htons(PORT);
    int socketDescriptor = socket(PF_INET, SOCK_DGRAM, 0);

    bind(socketDescriptor, (struct sockaddr* ) &sin, sizeof(sin));
    while(1){
        fflush(stdout);
        struct sockaddr_in sinR;
        int sin_len = sizeof(sinR);
        char messageRx[MAX_LEN];
        
        listen(socketDescriptor, 10);
        int sck = sizeof(struct sockaddr_in);
        int client = accept(socketDescriptor, (struct sockaddr* )& sinR, (socklen_t*)& sck );
        int size = recv(client, messageRx, MAX_LEN, 0);

       
        int terminateIdx = (size < MAX_LEN) ? size : MAX_LEN -1;
        printf("Message received: \n%s \n", messageRx);
        
        
        
        
    }
        //int incMe = atoi(messageRx);

    // int sock = init_socket();
    // printf("%d", sock);
    // lis(sock);

}