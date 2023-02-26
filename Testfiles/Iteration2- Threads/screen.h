// #include <pthread.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <stdio.h>
// #include "list.h"
// #ifndef _screen.h


// #define MAX_LEN 1024

 
// // Desc : 

// // Pop from the receive list and prints the message on the screen 



// static void* Print_message();




// // Desc 
// // Thread init 

// void*  Screen_init(void* unused);

// // Desc 
// // Thread shutdown
// void*  Screen_shutdown(void);

// #endif
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "list.h"
#include "receiver.h"

#ifndef _screen.h


#define MAX_LEN 1024


// Desc : 

// Pop from the receive list and prints the message on the screen 



static void* Print_message();




// Desc 
// Thread init 

void*  Screen_init(void* unused , pthread_cond_t* Cond , pthread_mutex_t* Lock);

// Desc 
// Thread shutdown
void*  Screen_shutdown(void);

#endif