#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int i, j, temp;
	long long int decimalNumber, quotient;
	char octalNumber[32] = { 0 };

	decimalNumber = atoll(argv[1]);
	quotient = decimalNumber;

	for (i = 0; quotient != 0; ++i) {
		temp = quotient % 8;
		octalNumber[i] = temp;
		quotient = quotient / 8;
	}

	printf("Equivalent octal value of decimal number %lld: ", decimalNumber);
	for (j = i - 1; j >= 0; --j)
		printf("%c", octalNumber[j]);
	printf("\n");
	return 0;
}
