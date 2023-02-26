#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#ifndef _keyboard.h


#define MAX_LEN 1024

// Function to init the Socket for() 
 
// Desc : 

// Asks the user input and Allocated memory to store the message 

// Pushes the new message to the shared list (between keyboard and sender)

static pthread_t keyboard_thread;
static pthread_cond_t KToSend = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t LockSender = PTHREAD_MUTEX_INITIALIZER;


static char*  New_message();





// Desc 
// Thread init 

 void*  Keyboard_process(void* Shared);



// Desc 
// Thread init 

void*  Keyboard_init(void* unused);

// Desc 
// Thread shutdown
void*  Keyboard_shutdown(void);

#endif
