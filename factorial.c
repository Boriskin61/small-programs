#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 2)
		return 1;

	int n, count;
	unsigned long long int factorial = 1;

	n = atoi(argv[1]);
	if (n < 0) {
		printf("Error!!! Factorial of negative number doesn't exist.\n");
	} else {
		for (count = 2; count <= n; ++count) {
			factorial *= count;
		}
		printf("Factorial = %llu\n", factorial);
	}
	return 0;
}
