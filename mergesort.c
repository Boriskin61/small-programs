#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int isNotDigit(char c) {
	printf("%c\n", c);
	return '0' < c || c > '9';
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int len = strlen(argv[1]);
	for (int i = 0; i < len; ++i) {
		if ('0' <= argv[1][i] && argv[1][i] <= '9') {
			continue;
		} else if (argv[1][i] == ' ') {
			continue;
		} else {
			printf("Invalid number in input string: %c\n", argv[1][i]);
			return 2;
		}
	}

	int count;
	char *next = argv[1];
	for (count = 0; strtol(next, &next, 10) || *next != '\0'; ++count) { ; }

	printf("numbers count = %d\n", count);
	int *nums = calloc(count, sizeof(int));
	if (!nums) {
		return 2;
	}

	next = argv[1];
	for (int i = 0; i < count; ++i) {
		nums[i] = strtol(next, &next, 10);
	}

	partition(nums, 0, count - 1);
	printf("After merge sorting elements are: ");
	for (int i = 0; i < count; ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	free(nums);
	return 0;
}

void partition(int arr[], int low, int high) {

	int mid;

	if (low < high) {
		mid = (low + high) / 2;
		partition(arr, low, mid);
		partition(arr, mid + 1, high);
		mergeSort(arr, low, mid, high);
	}
}

void mergeSort(int arr[], int low, int mid, int high) {

	int i, m, k, l, temp[MAX];

	l = low;
	i = low;
	m = mid + 1;

	while ((l <= mid) && (m <= high)) {

		if (arr[l] <= arr[m]) {
			temp[i] = arr[l];
			l++;
		} else {
			temp[i] = arr[m];
			m++;
		}
		i++;
	}

	if (l > mid) {
		for (k = m; k <= high; k++) {
			temp[i] = arr[k];
			i++;
		}
	} else {
		for (k = l; k <= mid; k++) {
			temp[i] = arr[k];
			i++;
		}
	}

	for (k = low; k <= high; k++) {
		arr[k] = temp[k];
	}
}
