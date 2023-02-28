
 //#include "keyboard.h"
// #include "screen.h"
// #include "receiver.h"
#include <pthread.h>
void Remove_Mutexes(pthread_mutex_t*, pthread_mutex_t*, pthread_cond_t*, pthread_cond_t*);

void Cancel_threads();