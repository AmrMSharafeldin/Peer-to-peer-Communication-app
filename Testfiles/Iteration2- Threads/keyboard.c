#include "keyboard.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include <string.h>
static int count = 0;


#define MAX_LEN 1024
static pthread_cond_t* Keyboard_Cond ;
static pthread_mutex_t* Keyboard_Lock;
// Function to init the Socket for() 
 
// Desc : 

// Asks the user input and Allocated memory to store the message 




char *  New_message(){
   // printf("Please enter new message\n");
    char* new_message = malloc(MAX_LEN);
    fgets( new_message, MAX_LEN, stdin);
    if((strlen(new_message) > 0)&& (new_message[strlen(new_message)-1] == '\n'))
    {
        new_message[strlen(new_message) - 1] = '\0';
    }
    return new_message;
    // To do : add the exception handleing 
}





// Desc 
// Thread init 

 void*  Keyboard_process(void* Arg){
         List* Shared  = (List*)Arg;
    while (1)
    {
    char* message = New_message();
      // Critical section;
    //mutex lock
    pthread_mutex_lock(Keyboard_Lock);
    {List_append(Shared , message);
    printf("%d keyboard\n" , List_count(Shared));
    } // critical section 
    pthread_mutex_unlock(Keyboard_Lock);
        //mutex unlock
    pthread_cond_signal(Keyboard_Cond);
     // Signal a thread 
    // Debuggin
    // free(message); // To avoid Mem leaks
    }
}


// Desc
 // Thread create 

 void*  Keyboard_init(void* Arg ,pthread_cond_t* Cond , pthread_mutex_t* Lock ){
     Keyboard_Cond = Cond;
     Keyboard_Lock = Lock;
     pthread_create(&keyboard_thread, NULL , Keyboard_process , Arg );
 }

// Desc 
// Thread shutdown
void* Keyboard_shutdown(void){
    // Cancel
   /// pthread_cancel(keyboard_thread);


    // Join 

    pthread_join(keyboard_thread , NULL);
}




