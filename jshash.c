#include <stdio.h>
#include <string.h>

unsigned int JSHash(char* str, unsigned int len) {
	unsigned int hash = 1315423911;
	unsigned int i = 0;

	for (i = 0; i < len; str++, i++) {
		hash ^= ((hash << 5) + (*str) + (hash >> 2));
	}
	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	} else {
		char *data = argv[1];
    	int len = strlen(data);
    	int hash = JSHash(data, len);
		printf("JSHash is 0x%08x\n", hash);
		return 0;
	}
}
