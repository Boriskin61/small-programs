#include <stdio.h>
#include <stdlib.h>

long long findgcd(long long x, long long y) {
	return x == y ? x : x > y ? findgcd(x - y, y) : findgcd(x, y - x);
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *arg2;
	char *arg1 = argv[1];
	long long
		gcd,
		num1 = strtoll(arg1, &arg2, 10),
		num2 = strtoll(arg2, NULL, 10);

	if (arg1 == arg2) {
		printf("Invalid input \"<num1> <num2>\"\n");
		return 2;
	}

	gcd = findgcd(num1, num2);
	printf("GCD of %lld and %lld is: %lld\n", num1, num2, gcd);
	return 0;
}

