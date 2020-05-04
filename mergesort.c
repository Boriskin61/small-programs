#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16

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
	int len = 0;
	if (argc < 2) {
		return 1;
	}

	partition(argv[1], 0, strlen(argv[1]) - 1);
	printf("After sorting: %s\n", argv[1]);
	return 0;
}
