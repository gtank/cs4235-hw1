#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned char *buf = malloc(8);
    unsigned char *target = malloc(8);

    unsigned long diff = (unsigned long)target - (unsigned long)buf;

    memset(target, 0x41, 7);
    target[7] = '\0';

    printf("target buffer: %s\n", target);
    printf("overflowing...\n");

    memset(buf, 0x42, diff + 7);

    printf("target buffer: %s\n", target);

    free(buf);
    free(target);

    return 0;
}
