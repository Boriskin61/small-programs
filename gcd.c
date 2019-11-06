#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}
	
	char *arg2;
	char *arg1 = argv[1];
	long long
		hcf,
		num1 = strtoll(arg1, &arg2, 10),
		num2 = strtoll(arg2, NULL, 10);

	if (arg1 == arg2) {
		printf("Invalid input \"<num1> <num2>\"\n");
		return 2;
	}

	for (int i = 1; i <= num1 || i <= num2; ++i) {
		if (num1%i == 0 && num2%i == 0) {
			hcf = i;
		}
	}
	printf("H.C.F of %lld and %lld is %lld\n", num1, num2, hcf);
	return 0;
}
