#include <stdio.h>
#include <string.h>

unsigned int DJBHash(char* str, unsigned int len) {
	unsigned int hash = 5381;
	unsigned int i = 0;

	for (i = 0; i < len; str++, i++) {
		hash = ((hash << 5) + hash) + (*str);
	}
	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	} else {
		char *data = argv[1];
    	int len = strlen(data);
    	int hash = DJBHash(data, len);
		printf("DJBHash is 0x%08x\n", hash);
		return 0;
	}
}
