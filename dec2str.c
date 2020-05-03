#include <stdio.h>
#include <stdlib.h>

int stringlen(const char *str) {
	int len = 0;
	while (*str++) {
		++len;
	}
	return len;
}

long long int str2lli(const char *str) {
    long long int res = 0;
	int len = stringlen(str);
    for (int i = 0; i < len; ++i) {
        res += str[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int i, j, temp;
	long long int decimalNumber, quotient;
	char stringNumber[32] = { 0 };

	decimalNumber = atoll(argv[1]);
	quotient = decimalNumber;

	for (i = 0; quotient != 0; ++i) {
		temp = quotient % 10;
		stringNumber[i] = '0' + temp;
		quotient = quotient / 10;
	}

	printf("Equivalent string value of decimal number %lld: \"", decimalNumber);
	for (j = i - 1; j >= 0; --j)
		printf("%c", stringNumber[j]);
	printf("\"\n");
	return 0;
}