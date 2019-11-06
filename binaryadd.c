#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *arg2;
	char *arg1 = argv[1];
	long long
		bin1 = strtoll(arg1, &arg2, 10),
		bin2 = strtoll(arg2, NULL, 10);

	if (arg1 == arg2) {
		printf("Invalid input \"<num1> <num2>\"\n");
		return 2;
	}

	int i = 0, r = 0, sum[64] = { 0 };

	while (bin1 != 0 || bin2 != 0) {
		sum[i++] = (bin1 % 10 + bin2 % 10 + r) % 2;
		r = (bin1 % 10 + bin2 % 10 + r) / 2;
		bin1 /= 10;
		bin2 /= 10;
	}

	if (r != 0) {
		sum[i++] = r;
	}

	--i;
	printf("Sum of two binary numbers: ");
	while (i >= 0) {
		printf("%d", sum[i--]);
	}
	printf("\n");

	return 0;
}
