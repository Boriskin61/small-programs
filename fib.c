#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

long long int str2lli(const char *str) {
    long long int res = 0;
	int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        res += str[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	long long n = str2lli(argv[1]);
	if (n <= 0) {
		printf("Error, input value must be greater than 0\n");
	} else {
		printf("fib(%lli)=%llu\n", n, fib(n));
	}
	return 0;
}
