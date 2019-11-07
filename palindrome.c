#include <stdio.h>
#include <stdlib.h>

int isDigit(char c) {
	return c >= '0' && c <= '9';
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int n, reverse = 0, rem, temp;
	n = strtol(argv[1], NULL, 10);
	if (!n && !isDigit(argv[1][0])) {
		return 2;
	}

	temp = n;
	while (temp != 0) {
		rem = temp % 10;
		reverse = reverse * 10 + rem;
		temp /= 10;
	}

	if (reverse == n) {
		printf("%d is sorted palindrome.\n", n);
	} else {
		printf("%d is not sorted palindrome.\n", n);
	}
	return 0;
}
