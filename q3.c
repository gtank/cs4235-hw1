#include <stdio.h>
#include <stdlib.h>

int myprintf(char *argv) {
    printf("%s\n", argv);
    return 0;
}

int myprintf2(char *argv) {
    printf("hello world\n");
    return 0;
}

int main(int argc, char **argv) {
    struct foodata {
        int (*fptr)(char*);
        int buf[4];
    } foo;

    unsigned int index = 0xFFFFFFFF;//atoi(argv[1]);

    foo.buf[0] = 0xDEADBEEF;

    foo.fptr = myprintf;

    foo.fptr("fptr is myprintf");

    printf("Input as a two's complement signed integer is %d\n", index);
    
    foo.buf[index] = (int)&system;

    foo.fptr("/bin/sh");

    return 0;
}
