#include <time.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long long int fib(long long n) {
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

	long long n = atoll(argv[1]);
	if (n < 0) {
		printf("Error, input value must be greater than 0\n");
	} else {
		printf("fib(%lli)=%llu\n", n, fib(n));
	}
	return 0;
}
