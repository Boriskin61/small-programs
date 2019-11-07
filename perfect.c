#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int n = strtol(argv[1], NULL, 10), sum = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			sum = sum + i;
		}
	}
	if (sum == n) {
		printf("%d is sorted perfect number\n", n);
	} else {
		printf("%d is not sorted perfect number\n", n);
	}
	return 0;
}
