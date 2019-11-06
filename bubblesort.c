#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return 1;
	}
	
	char *sorted = argv[1];
	int len = strlen(sorted);

	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (sorted[j] > sorted[j + 1]) {
				int temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}

	printf("After sorting: ");
	for (int i = 0; i < len; i++) {
		printf(" %d", sorted[i]);
	}
	printf("\n");
	return 0;
}
