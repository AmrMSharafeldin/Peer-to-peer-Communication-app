#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//int init_socket_receiver(); 


//void lis(int sock);

void* listenThread(void* args);
void* Receiver_init(void* Receive_List , pthread_cond_t* Cond , pthread_mutex_t* Lock);
void* Receiver_shutdown(void);