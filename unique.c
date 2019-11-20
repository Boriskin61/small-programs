#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int hasNotDigits(const char *num) {
	while (*num) {
		if (num < '0' || num > '9') {
			return TRUE;
		} else {
			++num;
		}
	}
	return FALSE;
}

char *ull2str(unsigned long long int n) {
	static char str[20];
	memset(str, 0, sizeof(str));
	sprintf(str, "%llu", n);
	return str;
}

unsigned long long int pow2(int n) {
	return n*n;
}

int main(int argc, char* argv[]) {
	int len = 0;
	unsigned long long int num = 0;
	if (argc < 2) {
		return 1;
	} else if ((len = strlen(argv[1])) > 20) {
		printf("To specify 64-bit integer maximum 20 decimial digits are used\n");
		return 2;
	} else if (hasNotDigits(argv[1])) {
		printf("Invalid number is specified, try to use only digits [0, 9]\n");
		return 3;
	}

	for (int i = 0; i < len; ++i) {
		num += pow2(argv[1][i] - '0');
	}

	if (!memcmp(argv[1], ull2str(num), len)) {
		printf("is an unique number\n");
	} else {
		printf("is not an unique number\n");
	}
	return 0;
}
