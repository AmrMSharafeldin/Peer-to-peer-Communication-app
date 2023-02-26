#include "screen.h"
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include <stdio.h>

static pthread_t Screen_thread;
static pthread_mutex_t* Screen_Lock;
static pthread_cond_t* Screen_Cond;
// Desc : 

// Pop from the receive list and prints the message on the screen 



static void* Print_message(void* Arg){
    List* Shared  = (List*)Arg;
    int n;
    while (1)
    {

        pthread_mutex_lock(Screen_Lock);
        {
             while(List_count(Shared) <= 0){
            pthread_cond_wait(Screen_Cond, Screen_Lock);
            }
            n = List_count(Shared);
            while(n!=0){
                char* message = List_trim(Shared);
                printf("A new message: %s\n", message);
                n--;
                
            } 
            
        }
        pthread_mutex_unlock(Screen_Lock);
        fflush(stdin);
        fflush(stdout); 
        //free(message); // To Do Fix that bug becasue it gave double free erorr ??
    }
}




// Desc 
// Thread init 

void*  Screen_init(void* Arg , pthread_cond_t* Cond , pthread_mutex_t* Lock){
    Screen_Cond = Cond;
    Screen_Lock = Lock;
         pthread_create(&Screen_thread, NULL , Print_message , Arg );

}

// Desc 
// Thread shutdown
void*  Screen_shutdown(void){
        // Cancel
   /// pthread_cancel(Screen_thread);


    // Join 

    pthread_join(Screen_thread , NULL);
}
