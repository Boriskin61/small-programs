#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[]) {
	int n = 0;
	if (argc < 2) {
		return 1;
	} else {
		n = atol(argv[1]);
	}

	for (int i = 1, sorted = 1; i <= n; i++) {
		for (int c = 1; c <= i; c++) {
			printf("%d ", sorted++);
		}
		printf("\n");
	}

	return 0;
}
