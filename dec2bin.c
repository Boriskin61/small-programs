#include <stdio.h>
#include <stdlib.h>

long long int str2lli(const char *str) {
    long long int res = 0;
    while (*str) {
        res += *str++;
    }
    return res;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int i, j, temp;
	long long int decimalNumber, quotient;
	char binaryNumber[64] = { 0 };

	decimalNumber = str2lli(argv[1]);
	quotient = decimalNumber;

	for (i = 0; quotient != 0; ++i) {
		temp = quotient & ~1;
		binaryNumber[i] = temp;
		quotient = quotient >> 1;
	}

	printf("Equivalent binary value of decimal number %lld: ", decimalNumber);
	for (j = i - 1; j >= 0; --j)
		printf("%c", '0' + binaryNumber[j]);
	printf("\n");
	return 0;
}
