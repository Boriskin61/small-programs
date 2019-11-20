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
	} else {
		char *data = argv[1];
    	int len = strlen(data);
    	int hash = SDBMHash(data, len);
		printf("SDBMHash is 0x%08x\n", hash);
		return 0;
	}
}
