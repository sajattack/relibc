#include <unistd.h>

int main(int argc, char** argv) {
    char *const args[1] = {"arg"};
    execvp("./exec.sh", args);
    perror("execvp");
}
