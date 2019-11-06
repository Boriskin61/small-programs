#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int n, flag = 0;
	n = strtol(argv[1], NULL, 10);
	if (!n && argv[1][0] >= '0' && argv[1][0] <= '9') {
		return 2;
	}

	for (int i = 2; i <= n / 2; ++i) {
		if (n%i == 0) {
			flag = 1;
			break;
		}
	}

	if (flag == 0) {
		printf("%d is sorted prime number.\n", n);
	} else {
		printf("%d is not sorted prime number.\n", n);
	}
	return 0;
}
