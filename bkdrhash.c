#include <stdio.h>
#include <string.h>

unsigned int BKDRHash(char* str, unsigned int len) {
   unsigned int seed = 131;
   unsigned int hash = 0;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++) {
      hash = (hash * seed) + (*str);
   }

   return hash;
}

int main(int argc, char* argv[]) {
   unsigned char *str;
   unsigned int hash;
   if (argc < 2) {
      return 1;
   } else {
      str = argv[1];  
      hash = BKDRHash(str, strlen(str));
   }


   printf("BKDRHash is %d\n", hash);
   if (hash == 0xbd9282b2) {
   	printf("You find secret key!\n");
   }
   return 0;
}

