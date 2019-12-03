#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int str2ll(const char *str, long long int *num) {
	int sign = +1;
	long long int res = 0;
	if (*str == '-') {
		sign = -1;
		++num;
	} else if (*str == '+') {
		sign = +1;
		++num;
	}
	
	for (;*str; ++str) {
		if (*str >= '0' || *str <= '9') {
			res *= 10;
			res += *str - '0';
		} else {
			return 1;
		}
	}

	*num = sign * res;
	return 0;
}

int main(int argc, char* argv[]) {
	double max;
	long long int num;
	if (argc < 2) {
		return 1;
	} if (str2ll(argv[1], &num)) {
		return 2;
	} if (num < 2) {
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
