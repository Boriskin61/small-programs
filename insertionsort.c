#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *sorted = argv[1];
	int len  = strlen(sorted);

	for (int i = 1; i < len ; i++) {
		int temp = sorted[i];
		int j = i - 1;
		while ((temp < sorted[j]) && (j >= 0)) {
			sorted[j + 1] = sorted[j];
			j = j - 1;
		}
		sorted[j + 1] = temp;
	}

	printf("After sorting: ");
	for (int i = 0; i < len; i++) {
		printf(" %c", sorted[i]);
	}
	printf("\n");
	return 0;
}
