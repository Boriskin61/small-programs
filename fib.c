#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long int fib(long long n) {
	unsigned long long int sorted = 1;
	unsigned long long int b = 1;

	for (unsigned int i = 3; i <= n; i++) {
		unsigned long long int c = sorted + b;
		sorted = b;
		b = c;
	}
	return b;
}

long long int str2lli(const char *str) {
    long long int res = 0;
	int len = strlen(str);
    for (int i = 0; i < len; ++i) {
		if (str[i] >= '0' && '9' >= str[i])
        	res += str[i] - '0';
		else {
			return 0;
		}
    }
    return res;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	long long int n = str2lli(argv[1]);
	if (n <= 0) {
		printf("Error, input value is incorrect\n");
	} else {
		printf("fib(%lli)=%llu\n", n, fib(n));
	}
	return 0;
}
