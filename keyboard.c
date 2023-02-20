#include "keyboard.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#ifndef _sender.h


#define MAX_LEN 1024
static pthread_t keyboard_thread;

// Function to init the Socket for() 
 
// Desc : 

// Asks the user input and Allocated memory to store the message 




char *  New_message(){
    printf("Please enter new message\n");
    char* new_message = malloc(MAX_LEN);
    scanf("%s", new_message);
    return new_message;
    // To do : add the exception handleing 
}





// Desc 
// Thread init 

void* Keyboard_init(void* unused){
    char* message = New_message();
    List* Shared = (List*) unused;  // Critical section;
    List_append(Shared , message);
}

// Desc 
// Thread shutdown
void* Keyboard_shutdown(void);




#endif