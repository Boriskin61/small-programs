#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(char *x, int first, int last) {
	int pivot, j, temp, i;
	if (first < last) {
		pivot = first;
		i = first;
		j = last;

		while (i < j) {
			while (x[i] <= x[pivot] && i < last)
				i++;
			while (x[j] > x[pivot])
				j--;
			if (i < j) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}

		temp = x[pivot];
		x[pivot] = x[j];
		x[j] = temp;
		quicksort(x, first, j - 1);
		quicksort(x, j + 1, last);
	}
}

int main(int argc, char* argv[]) {
	char *sorted;
	int count;
	if (argc < 2) {
		return 1;
	} else {
		count = strlen(argv[1]);
	}

	sorted = calloc(count + 1, sizeof(char));
	if (!sorted) {
		return 2;
	} else {
		for (int i = 0; i < count; ++i) {
			sorted[i] = argv[1][i];
		}
	}

	quicksort(sorted, 0, count - 1);
	printf(
		"Before sorting is: %s\n"
		"After sorting is: %s\n",
		argv[1], sorted);

	free(sorted);
	return 0;
}
