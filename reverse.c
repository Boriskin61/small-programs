#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int num, r, reverse = 0;
	if (argc < 2) {
		return 1;
	} else {
		num = strtol(argv[1], NULL, 10);
	}

	while (num) {
		r = num % 10;
		reverse = reverse * 10 + r;
		num = num / 10;
	}

	printf("Reversed of number: %d\n", reverse);
	return 0;
}