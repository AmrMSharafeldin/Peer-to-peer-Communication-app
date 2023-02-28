#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "list.h"
#include "receiver.h"
#include "ThreadCancelHandler.h"
#ifndef _screen_h


#define MAX_LEN 1024


// Desc : 

// Pop from the receive list and prints the message on the screen 



//  void* Print_message(void* Arg); // Static functinos should only be declared in the source file 




// Desc 
// Thread init 

void*  Screen_init(void* unused , pthread_cond_t* Cond , pthread_mutex_t* Lock);

// Desc 
// Thread shutdown
void*  Screen_shutdown(void);


void Cancel_Screen();
#endif