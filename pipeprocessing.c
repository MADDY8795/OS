
#include <unistd.h> 
#include <stdlib.h>  
#include <stdio.h> 
#include <string.h> 

#define MSG_LEN 64  

int main() { 
    int fd[2]; 
    char message[MSG_LEN] = "Linux World!! Understanding Concepts of Piping";
    char recvd_msg[MSG_LEN];  
    
    if (pipe(fd) < 0) { 
        perror("pipe");  
        exit(1); 
    } 
    
    if (write(fd[1], message, strlen(message)) < 0) { 
        perror("write"); 
        exit(2); 
    } 
    
    if (read(fd[0], recvd_msg, MSG_LEN) < 0) { 
        perror("read");  
        exit(3); 
    } 
    
    printf("%s\n", recvd_msg); 
    return 0; 
}
