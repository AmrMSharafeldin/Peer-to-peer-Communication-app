#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
struct sockaddr_in sin;
struct sockaddr_in sinRemote;
int init_socket_receiver(); 

void lis(int sock);