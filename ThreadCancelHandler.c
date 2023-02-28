// #ifndef _ThreadCancelHandler_h
// #define _ThreadCancelHandler_h
#include "keyboard.h"
#include "screen.h"
#include "receiver.h"
#include "sender.h"

void Cancel_threads(bool caller){
    if(caller == false){
        Cancel_Receiver();
    Cancel_Screen();
    Cancel_Keyboard();     // If we send ! 
    }

    else {
        Cancel_Receiver();
    Cancel_Sender();   // If we receive send! 
    Cancel_Keyboard();
    }
    
}
// #endif