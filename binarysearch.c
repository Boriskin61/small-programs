#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int sorted[10], i, m, c = 0, l, u, mid;
	for (i = 1; i < argc - 1; ++i) {
		sorted[i - 1] = argv[i][0];
	}

	m = (int)argv[argc - 1][0];

	l = 0, u = argc - 2;
	while (l <= u) {
		mid = (l + u) / 2;
		if (m == sorted[mid]) {
			c = 1;
			break;
		} else if (m < sorted[mid]) {
			u = mid - 1;
		} else
			l = mid + 1;
	}
	if (c == 0) {
		printf("The number is not found.\n");
	} else {
		printf("The number is found.\n");
	}
	return 0;
}
