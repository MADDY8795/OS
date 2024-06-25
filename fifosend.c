#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILE "MYFIFO"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("USAGE: fifoclient [string]\n");
        exit(1);
    }

    int fd = open(FIFO_FILE, O_WRONLY);
    write(fd, argv[1], strlen(argv[1]) + 1);  // Write the null-terminated string
    close(fd);

    return 0;
}
