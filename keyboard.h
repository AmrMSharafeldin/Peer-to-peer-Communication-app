#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#ifndef _keyboard_h


#define MAX_LEN 1024

// Function to init the Socket for() 
 
// Desc : 

// Asks the user input and Allocated memory to store the message 

// Pushes the new message to the shared list (between keyboard and sender)




// static char*  New_message();





// Desc 
// Thread init 

 void*  Keyboard_process(void* Shared);



// Desc 
// Thread init 

void*  Keyboard_init(void* Arg ,pthread_cond_t* Cond , pthread_mutex_t* Lock);

// Desc 
// Thread shutdown
void*  Keyboard_shutdown(void);



void*  Cancel_Keyboard(void);

#endif
