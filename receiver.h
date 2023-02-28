#include "list.h"
#include <pthread.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

//int init_socket_receiver(); 


//void lis(int sock);

void* listenThread(void* args);
void* Receiver_init(void* Receive_List , pthread_cond_t* Cond , pthread_mutex_t* Lock, short CLIENT_PORT,char* IP);
void* Receiver_shutdown(void);
void Cancel_Receiver();