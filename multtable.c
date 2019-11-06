#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isDigit(char c) {
	return c >= '0' && c <= '9';
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int n = strtol(argv[1], NULL, 10);
	if (!n && !isDigit(argv[1][0])) {
		return 2;
	}

	for (int i = 1; i <= 10; ++i) {
		printf("%d * %d = %d\n", n, i, n*i);
	}
	return 0;
}
