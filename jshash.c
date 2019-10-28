#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int JSHash(char* str, unsigned int len) {
   unsigned int hash = 1315423911;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++) {
      hash ^= ((hash << 5) + (*str) + (hash >> 2));
   }
   return hash;
}

int main(int argc, char* argv[]) {
   if (argc < 2)
      return 1;
   unsigned char *str = argv[1];
   unsigned int hash = JSHash(str, strlen(str));
  
   printf("JSHash is %x\n", hash);
   if (hash == 0x120bdadd)
      printf("You find secret key!\n");
   return 0;
}

