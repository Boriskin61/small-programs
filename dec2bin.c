#include <stdio.h>
#include <stdlib.h>

long long int str2lli(const char *str) {
    long long int res = 0;
    while (*str) {
        res += (unsigned)*str++;
    }
    return res;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char binaryNumber[64];
	long long int decimalNumber = str2lli(argv[1]);
	long long int quotient = decimalNumber;
	int i;
	
	for (i = 0; quotient != 0; ++i) {
		binaryNumber[i] = quotient % 2 ? '1' : '0';
		quotient >>= 1;
	}

	printf("Equivalent binary value of decimal number %lld: ", decimalNumber);
	for (int j = i - 1; j >= 0; --j)
		printf("%c", binaryNumber[j]);
	printf("\n");
	return 0;
}
