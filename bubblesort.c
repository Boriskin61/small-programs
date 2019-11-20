#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int len;
	char *sorted;

	if (argc < 2) {
		return 1;
	} else {
		sorted = argv[1];
		len = strlen(sorted);
	}

	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sorted[j] > sorted[j + 1]) {
				sorted[j] ^= sorted[j + 1];
				sorted[j + 1] ^= sorted[i];
				sorted[j] ^= sorted[j + 1];
			}
		}
	}

	printf("After sorting is: %s\n", sorted);
	return 0;
}
