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
	if (argc < 2) {
		return 1;
	} else {
      char *data = argv[1];
      int len = strlen(data);
      int hash = BKDRHash(data, len);
		printf("BKDRHash is 0x%08x\n", hash);
		return 0;
	}
}

