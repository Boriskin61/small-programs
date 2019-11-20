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
	} else {
		char *data = argv[1];
    	int len = strlen(data);
    	int hash = RSHash(data, len);
		printf("RSHash is 0x%08x\n", hash);
		return 0;
	}
}