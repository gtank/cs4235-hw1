#include <stdio.h>

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

    foo.buf[0] = 0xDEADBEEF;

    foo.fptr = myprintf;

    foo.fptr("fptr is myprintf");

    printf("0xFFFFFFFF as a two's complement signed integer is %d\n", 0xFFFFFFFF);
    
    foo.buf[0xFFFFFFFF] = (int)myprintf2;

    foo.fptr("this argument doesn't matter");

    return 0;
}
