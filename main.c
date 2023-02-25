#include "receiver.h"
#include "sender.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "ThreadArgs.h"
pthread_mutex_t lock;
static List aList;
int main()
{
   tar* arguments = (tar*)malloc(sizeof(tar));
   arguments->lock = &lock;
   arguments->list = &aList;
}
