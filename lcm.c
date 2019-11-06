#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *arg2;
	char *arg1 = argv[1];
	long
		max,
		num1 = strtol(arg1, &arg2, 10),
		num2 = strtol(arg2, NULL, 10);

	if (arg1 == arg2) {
		printf("Invalid input \"<num1> <num2>\"\n");
		return 2;
	}
	
	for (max = num1 > num2 ? num1 : num2; max%num1 != 0 || max%num2 != 0; ++max) { ; }

	printf("LCM of %d and %d is %d\n", num1, num2, max);
	return 0;
}
