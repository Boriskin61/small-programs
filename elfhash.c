#include <stdio.h>
#include <string.h>

unsigned int ELFHash(char* str, unsigned int len) {
	unsigned int hash = 0;
	unsigned int x = 0;
	unsigned int i = 0;

	for (i = 0; i < len; str++, i++) {
		hash = (hash << 4) + (*str);
		if ((x = hash & 0xF0000000L) != 0) {
			hash ^= (x >> 24);
		}
		hash &= ~x;
	}
	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	} else {
		char *data = argv[1];
    	int len = strlen(data);
    	unsigned int hash = ELFHash(data, len);
		printf("ELFHash is 0x%08x\n", hash);
		return 0;
	}
}

