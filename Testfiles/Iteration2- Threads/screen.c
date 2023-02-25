// #include "screen.h"
// #include <pthread.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include "list.h"
// #include <stdio.h>

// static pthread_t Screen_thread;

// // Desc : 

// // Pop from the receive list and prints the message on the screen 



// static void* Print_message(void* Arg){
//     List* Shared  = (List*)Arg;
//     while (1)
//     {
        
    
    
//     if(List_count(Shared) == 0){continue;}

//     char* message = List_remove(Shared);
//     printf("incoming message %s \n",message);
//     fflush(stdin);
//     fflush(stdout); 
//     //free(message); // To Do Fix that bug becasue it gave double free erorr ??
// }
// }




// // Desc 
// // Thread init 

// void*  Screen_init(void* Arg){
//          pthread_create(&Screen_thread, NULL , Print_message , Arg );

// }

// // Desc 
// // Thread shutdown
// void*  Screen_shutdown(void){
//         // Cancel
//    /// pthread_cancel(Screen_thread);


//     // Join 

//     pthread_join(Screen_thread , NULL);
// }
#include "screen.h"
#include <pthread.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include <stdio.h>

static pthread_t Screen_thread;

// Desc : 

// Pop from the receive list and prints the message on the screen 



static void* Print_message(void* Arg){
    List* Shared  = (List*)Arg;
    while (1)
    {
        if(List_count(Shared) == 0){continue;}

        pthread_mutex_lock(&LockIn);
        {
            pthread_cond_wait(&kToPrint, &LockIn);

            int n = List_count(Shared);

            while(n!=0){
                char* message = List_trim(Shared);
                printf("A new message: %s", message);
                free(message);
                n--;
            } 
        }
        pthread_mutex_unlock(&LockIn);
        fflush(stdin);
        fflush(stdout); 
        //free(message); // To Do Fix that bug becasue it gave double free erorr ??
    }
}




// Desc 
// Thread init 

void*  Screen_init(void* Arg){
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
