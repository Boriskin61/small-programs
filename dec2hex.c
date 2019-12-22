#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int i, j, temp;
	long long int decimalNumber, quotient;
	char hexadecimalNumber[16] = { 0 };

	decimalNumber = atoll(argv[1]);
	quotient = decimalNumber;

	for (i = 0; quotient != 0; ++i) {
		temp = quotient % 16;
		temp += temp < 10 ? '0' : 'A' - 10;
		hexadecimalNumber[i] = temp;
		quotient = quotient / 16;
	}

	printf("Equivalent hexadecimal value of decimal number %lld: 0x", decimalNumber);
	for (j = i - 1; j >= 0; --j)
		printf("%c", hexadecimalNumber[j]);
	printf("\n");
	return 0;
}
