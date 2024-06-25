#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

// structure for message queue 
struct mesg_buffer { 
    long msg_type; 
    char msg_text[100]; 
} message; 

int main() { 
    key_t key; 
    int msgid; 

    // generate unique key 
    key = ftok("progfile", 65); 

    // create message queue and return identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 

    message.msg_type = 1; 
    printf("Write Data: "); 
    fgets(message.msg_text, sizeof(message.msg_text), stdin); 

    // send message 
    msgsnd(msgid, &message, sizeof(message), 0); 

    // display the message 
    printf("Data sent is: %s\n", message.msg_text); 

    return 0; 
}
