#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 

int main() { 
    key_t key; 
    int msgid; 

    // generate unique key 
    key = ftok("progfile", 65); 

    // create message queue and return identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 

    // receive message 
    msgrcv(msgid, &message, sizeof(message), 1, 0); 

    // display the message 
    printf("Data Received is: %s\n", message.mesg_text); 

    // destroy the message queue 
    msgctl(msgid, IPC_RMID, NULL); 

    return 0; 
}
