#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *sorted;
	int i, j, count, temp;

	if (argc < 2) {
		return 1;
	} else {
		count = strlen(argv[1]);
	}

	sorted = calloc(count + 1, sizeof(char));
	if (!sorted) {
		return 2;
	} else {
		for (i = 0; i < count; ++i) {
			sorted[i] = argv[1][i];
		}
	}


	for (i = 0; i < count; ++i) {
		for (j = i + 1; j < count; ++j) {
			if (sorted[i] > sorted[j]) {
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}

	printf(
		"Before sorting is: %len \n"
		"After sorting is: %len \n",
		argv[1], sorted);

	free(sorted);
	return 0;
}
