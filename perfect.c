#include <stdio.h>
#include <stdlib.h>

int str2ll(const char *str, long long int *num) {
	int sign = 0;
	long long int res = 0;
	if (*str == '-') {
		sign = -1;
		++num;
	} else if (*str == '+') {
		sign = +1;
		++num;
	} else {
		sign = +1;
	}
	
	for (;*str; ++str) {
		if (*str < '0' || *str > '9') {
			return 1;
		} else {
			res = res * 10 + sign * (*str - '0');
		}
	}

	*num = res;
	return 0;
}

int main(int argc, char* argv[]) {
	long long int i, n, sum;
	if (argc < 2) {
		return 1;
	} else if (str2ll(argv[1], &n)) {
		return 2;
	} else if (n == 0) {
		return 3;
	} else if (n < 6)  {
		sum = n - 1;
	} else if (n == 6) {
		sum = n;
	} else if (n % 2) {
		sum = n - 1;
	} else {
		sum = n / 2 + 2 + 1;
		for (i = 3; i < n/2; ++i) {
			if (n % i == 0) {
				sum += i;
			}
		}
	}

	if (sum == n) {
		printf("%lld is perfect number\n", n);
	} else {
		printf("%lld is not perfect number\n", n);
	}
	return 0;
}
