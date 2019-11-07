#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
	int sorted = 1;
	int b = 1;

	for (int i = 3; i <= n; i++) {
		int c = sorted + b;
		sorted = b;
		b = c;
	}
	return b;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int n = strtol(argv[1], NULL, 10);
	if (n < 0) {
		printf("Error, input value must be greater than 0\n");
	} else {
		printf("fib(%li)=%i\n", n, fib(n));
	}
	return 0;
}
