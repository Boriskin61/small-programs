#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int DEKHash(char* str, unsigned int len) {
   unsigned int hash = len;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++) {
      hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
   }
   return hash;
}

int main(int argc, char* argv[]) {
   if (argc < 2) {
      return 1;
   }
   unsigned char *str = argv[1]; 
   unsigned int hash = DEKHash(str, strlen(str));

   printf("DEKHAsh is %x\n", hash);
   if (hash == 0xde4363b7)
   	printf("You find secret key!\n");
   return 0;
}

