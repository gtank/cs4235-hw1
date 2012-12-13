#include <stdio.h>

int myprint(char *argv1) {
    printf("%s", argv1);
}

void foo(char *argv1, char* argv2) {
    int (*fptr)(char*) = myprint;
    char buf[12];
    strcpy(buf, argv1);
    fptr(argv2);
}

int main(int argc, char **argv) {
    int i;

    if(argc < 3) {
        printf("error\n");
        return;
    }

    for(i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    foo(argv[1], argv[2]);
}

