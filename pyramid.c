#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int rows = strtol(argv[1], NULL, 10);
	for (int i = 1; i <= rows; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
