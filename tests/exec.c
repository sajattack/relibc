#include <unistd.h>

int main(int argc, char** argv) {
    execl("/bin/sh", "-c", "./exec.sh");
    perror(execl);
}
