#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int stringlen(const char *str) {
	int len = 0;
	while (*str++) {
		++len;
	}
	return len;
}

long long int str2lli(const char *str) {
    long long int res = 0;
	int len = stringlen(str);
    for (int i = 0; i < len; ++i) {
        res += str[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
	double max;
	long long int num;
	if (argc < 2) {
		return 1;
	}

	num = str2lli(argv[1]);
	if (!num) {
		return 2;
	} else if (num < 2) {
		return 3;
	} else {
		max = sqrt(num);
	}

	for (int i = 2; i <= max; ++i) {
		if (num % i == 0) {
			printf("%lld is not prime number.\n", num);
			return 0;
		}
	}

	printf("%lld is prime number.\n", num);
	return 0;
}
