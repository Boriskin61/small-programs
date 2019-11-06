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
	}
	unsigned char *str = argv[1];
	unsigned int hash = DJBHash(str, strlen(str));

	printf("DJBHash is %x\n", hash);
	if (hash == 0x49a54935)
		printf("You find secret key!\n");
	return 0;
}

