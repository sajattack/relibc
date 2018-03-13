#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    char * s = "azAZ9."; // test boundaries
    long l = a64l(s);
    if (l != 194301926) {
        printf("Invalid result: a64l(%s) = %ld\n", s, l);
        return 1;
    }
    printf("Correct a64l: %s = %ld\n", s, l);

    
    s = "azA"; // test null terminated string
    l = a64l(s);
    if (l != 53222) {
        printf("Invalid result: a64l(%s) = %ld\n", s, l);
        return 1;
    }
    printf("Correct a64l: %s = %ld\n", s, l);
    return 0;
}
