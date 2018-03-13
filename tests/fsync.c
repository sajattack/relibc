#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main (int argc, char** argv) {
    int fd = open(".", 0, 0);
    int status;
    status = fsync(fd);
    printf("fsync exited with status code %d\n", status);
    close(fd);
    return 0;
}
