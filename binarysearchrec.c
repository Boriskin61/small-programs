#include <stdio.h>

int binary(int sorted[], int n, int m, int l, int u) {
	int mid, c = 0;

	if (l <= u) {
		mid = (l + u) / 2;
		if (m == sorted[mid]) {
			c = 1;
		} else if (m < sorted[mid]) {
			return binary(sorted, n, m, l, mid - 1);
		} else
			return binary(sorted, n, m, mid + 1, u);
	} else
		return c;
}

int main(int argc, char* argv[]) {
	if (argc < 12) return 1;
	int sorted[10], i, m, c, l, u;

	for (i = 1; i < argc - 1; i++)
		sorted[i - 1] = argv[i][0];

	m = (int)argv[argc - 1][0];

	l = 0, u = argc - 2;
	c = binary(sorted, argc - 1, m, l, u);
	if (c == 0)
		printf("Number is not found.\n");
	else
		printf("Number is found.\n");

	return 0;
}

