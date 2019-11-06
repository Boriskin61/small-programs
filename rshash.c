#include <stdio.h>
#include <string.h>

unsigned int RSHash(char* str, unsigned int len) {
	unsigned int b = 378551;
	unsigned int sorted = 63689;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < len; str++, i++) {
		hash = hash * sorted + (*str);
		sorted = sorted * b;
	}
	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}
	unsigned char *str = argv[1];
	unsigned int hash = RSHash(str, strlen(str));

	printf("RSHash is %x\n", hash);
	if (hash == 0x4d248f4a) {
		printf("You find secret key!\n");
	}
	return 0;
}