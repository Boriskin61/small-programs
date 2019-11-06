#include <stdio.h>
#include <string.h>

unsigned int SDBMHash(char* str, unsigned int len) {
	unsigned int i, hash = 0;
	for (i = 0; i < len; str++, i++) {
		hash = (*str) + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}
	unsigned char *str = argv[1];
	unsigned int hash = SDBMHash(str, strlen(str));

	printf("SDBMHash is %x\n", hash);
	if (hash == 0x89dcd66e) {
		printf("You find secret key!\n");
	}
	return 0;
}
