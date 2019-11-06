#include <stdio.h>
#include <string.h>

unsigned int PJWHash(char* str, unsigned int len) {
	const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
	const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
	const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
	const unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
	unsigned int hash = 0;
	unsigned int test = 0;
	unsigned int i = 0;

	for (i = 0; i < len; str++, i++) {
		hash = (hash << OneEighth) + (*str);
		if ((test = hash & HighBits) != 0) {
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return hash;
}

int main(int argc, char* argv[]) {
	if (argc < 2)
		return 1;
	unsigned char *str = argv[1];
	unsigned int hash = PJWHash(str, strlen(str));

	printf("PJWHash is %x\n", hash);
	if (hash == 0xaf9bec9)
		printf("You find secret key!\n");
	return 0;
}

