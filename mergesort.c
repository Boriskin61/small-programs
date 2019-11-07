#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void mergeSort(char arr[], int low, int mid, int high) {
	int i, m, k, l, temp[MAX];

	l = low;
	i = low;
	m = mid + 1;

	while ((l <= mid) && (m <= high)) {
		temp[i++] = arr[l] <= arr[m] ? arr[l++] : arr[m++];
	}

	if (l > mid) {
		for (k = m; k <= high; k++) {
			temp[i++] = arr[k];
		}
	} else {
		for (k = l; k <= mid; k++) {
			temp[i++] = arr[k];
		}
	}

	for (k = low; k <= high; k++) {
		arr[k] = temp[k];
	}
}

void partition(char arr[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		partition(arr, low, mid);
		partition(arr, mid + 1, high);
		mergeSort(arr, low, mid, high);
	}
}

int main(int argc, char* argv[]) {
	int count = 0;
	if (argc < 2) {
		return 1;
	} else {
		count = strlen(argv[1]);
	}

	char *sorted = calloc(count + 1, sizeof(char));
	if (!sorted) {
		return 2;
	} else {
		for (int i = 0; i < count; ++i) {
			sorted[i] = argv[1][i];
		}
	}

	partition(sorted, 0, count - 1);
	printf(
		"Before sorting is: %s\n"
		"After sorting is: %s\n",
		argv[1], sorted);

	free(sorted);
	return 0;
}

