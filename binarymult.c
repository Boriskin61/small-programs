#include <stdio.h>
#include <stdlib.h>

int binaryAddition(long long int bin1, long long int bin2) {
	int i = 0, remainder = 0, sum[64];
	int binarySum = 0;

	while (bin1 != 0 || bin2 != 0) {
		sum[i++] = (bin1 % 10 + bin2 % 10 + remainder) % 2;
		remainder = (bin1 % 10 + bin2 % 10 + remainder) / 2;
		bin1 /= 10;
		bin2 /= 10;
	}

	if (remainder != 0) {
		sum[i++] = remainder;
	}

	while (--i >= 0) {
		binarySum = binarySum * 10 + sum[i];
	}
	return binarySum;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *arg2;
	char *arg1 = argv[1];
	long long int
		mul = 0,
		bin1 = strtoll(arg1, &arg2, 10),
		bin2 = strtoll(arg2, NULL, 10);

	if (arg1 == arg2) {
		printf("Invalid input \"<num1> <num2>\"\n");
		return 2;
	}

	int digit, factor = 1;

	while (bin2 != 0) {
		digit = bin2 % 10;
		bin1 *= factor;
		mul = digit == 1 ? binaryAddition(bin1, mul) : mul; 
		bin2 = bin2 / 10;
		factor = 10;
	}

	printf("Product of two binary numbers: %ld\n", mul);
	return 0;
}


