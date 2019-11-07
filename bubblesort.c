#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int len = 0;
	if (argc < 2) {
		return 1;
	} else {
		len = strlen(argv[1]);
	}

	char *sorted = calloc(len + 1, sizeof(char));
	if (!sorted) {
		return 2;
	} else {
		for (int i = 0; i < len; ++i) {
			sorted[i] = argv[1][i];
		}
	}

	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sorted[j] > sorted[j + 1]) {
				int temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}

	printf(
		"Before sorting is: %s\n"
		"After sorting is: %s\n",
		argv[1], sorted);
	free(sorted);
	return 0;
}
