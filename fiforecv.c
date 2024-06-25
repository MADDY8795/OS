#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_FILE "MYFIFO"

int main(void) {
    char readbuf[100];

    // Create the FIFO if it does not exist
    umask(0);
    mknod(FIFO_FILE, S_IFIFO | 0666, 0);

    while (1) {
        int fd = open(FIFO_FILE, O_RDONLY);
        read(fd, readbuf, sizeof(readbuf));
        printf("Received string: %s\n", readbuf);
        close(fd);
    }

    return 0;
}