#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *sorted;
	int len, tmp;
	if (argc < 2) {
		return 1;
	} else {
		sorted = argv[1];
		len = strlen(sorted);
	}

	for (int i = 1; i < len ; i++) {
		int tmp = sorted[i];
		int j = i - 1;
		while ((j >= 0) && (tmp < sorted[j])) {
			sorted[j + 1] = sorted[j];
			j = j - 1;
		}
		sorted[j + 1] = tmp;
	}

	printf("After sorting: ");
	for (int i = 0; i < len; i++) {
		printf(" %c", sorted[i]);
	}
	printf("\n");
	return 0;
}
