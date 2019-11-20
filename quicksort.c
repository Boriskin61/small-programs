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
	int len;
	if (argc < 2) {
		return 1;
	} else {
		sorted = argv[1];
		len = strlen(sorted);
	}

	quicksort(sorted, 0, len - 1);
	printf("After sorting: %s\n", sorted);
	return 0;
}
