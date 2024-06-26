#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct mesg_buffer { 
    long msg_type; 
    char msg_text[100]; 
} message; 

int main() { 
    key_t key; 
    int msgid; 

    key = ftok("progfile", 65); 

    msgid = msgget(key, 0666 | IPC_CREAT); 

    message.msg_type = 1; 
    printf("Write Data: "); 
    fgets(message.msg_text, sizeof(message.msg_text), stdin); 

    msgsnd(msgid, &message, sizeof(message), 0); 

    printf("Data sent is: %s\n", message.msg_text); 

    return 0; 
}
