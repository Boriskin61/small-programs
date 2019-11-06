#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int i, j, rows;
	if (argc < 2) {
		return 1;
	}

	rows = strtol(argv[1], NULL, 10);
	for (int i = 1; i <= rows; ++i) {
		for (j = 1; j <= i; ++j) {
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
