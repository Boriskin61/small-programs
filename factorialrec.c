#include <stdio.h>
#include <stdlib.h>

long long int fact(int n) {
	return n > 1 ? n*fact(n - 1) : 1;
}

int main(int argc, char* argv[]) {
	int n = 0;
	if (argc < 2) {
		return 1;
	} else {
		n = atoi(argv[1]);
	}

	if (n < 0) {
		printf("Error!!! Factorial of negative number doesn't exist.\n");
	} else {
		printf("\nFactorial of %d is: %;lld\n", n, fact(n));
	}
	return 0;
}
