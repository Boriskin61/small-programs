#include <stdio.h>
#include <string.h>

unsigned int FNVHash(char* str, unsigned int len) {
	const unsigned int fnv_prime = 0x811C9DC5;
	unsigned int hash = 0;
	unsigned int i = 0;

	for (i = 0; i < len; str++, i++) {
		hash *= fnv_prime;
		hash ^= (*str);
	}
	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	} else {
		char *data = argv[1];
    	int len = strlen(data);
    	int hash = FNVHash(data, len);
		printf("FNVHash is 0x%08x\n", hash);
		return 0;
	}
}

