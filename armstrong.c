#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isDigit(char c) {
	return c >= '0' && c <= '9';
}

int main(int argc, char* argv[]) {
	long long n, tmp;
	int rem, num = 0;

	if (argc < 2) {
		return 1;
	}

	n = strtoll(argv[1], NULL, 10);
	tmp = n;
	while (tmp != 0) {
		rem = tmp % 10;
		num += rem*rem*rem;
		tmp /= 10;
	}
	if (num == n) {
		printf("is an Armstrong number.");
	} else {
		printf("is not an Armstrong number.");
	}
}
