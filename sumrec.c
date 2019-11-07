#include <stdio.h>
#include <stdlib.h>

unsigned int findsum(unsigned int n) {
	return n < 10 ? n : n % 10 + findsum(n / 10);
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int num = strtol(argv[1], NULL, 10);
	if (num <= 0) {
		printf("Unacceptable number. Specify the number greater than 0\n");
	}

	printf("Sum of the digits of %d is: %x\n", num, findsum(num));
	return 0;
}