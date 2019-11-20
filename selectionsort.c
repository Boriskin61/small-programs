#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *sorted;
	int i, j, len, tmp;

	if (argc < 2) {
		return 1;
	} else {
		sorted = argv[1];
		len = strlen(sorted);
	}

	for (i = 0; i < len; ++i) {
		for (j = i + 1; j < len; ++j) {
			if (sorted[i] > sorted[j]) {
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
		}
	}

	printf("After sorting: %s\n", sorted);
	return 0;
}
