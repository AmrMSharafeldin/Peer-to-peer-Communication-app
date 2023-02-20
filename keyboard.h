#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#ifndef _sender.h


#define MAX_LEN 1024

// Function to init the Socket for() 
 
// Desc : 

// Asks the user input and Allocated memory to store the message 

// Pushes the new message to the shared list (between keyboard and sender)


static int New_message();

// Desc 
// Creates the function for  keyboard

void Keyboard() ; 



// Desc 
// Thread init 

void* Keyboard_init(void* unused);

// Desc 
// Thread shutdown
void* Keyboard_shutdown(void);




#endif