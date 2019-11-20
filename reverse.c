#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int len;
	char *str;
	if (argc < 2) {
		return 1;
	} else {
		str = argv[1];
		len = strlen(str);
	}

	for (int i = 0, end = len >> 1; i < end; ++i) {
		str[i] ^= str[len - i - 1];
		str[len - i - 1] ^= str[i];
		str[i] ^= str[len - i - 1];
	}

	printf("Reversed: %s\n", str);
	return 0;
}