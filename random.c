#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char* argv[]) {
	int x, len;
	if (argc < 2) {
		return 1;
	} else {
		len = strlen(argv[1]);
	}

	srand(time(NULL));
	printf("%d random numbers in range [1, ascii code]: \n", len);
	for (int i = 1; i <= len; ++i) {
		int n = rand() % argv[1][i] + 1;
		printf("%d ", n);
	}
	printf("\n");

	return 0;
}
