#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_max(int *nums, int count) {
	int max = nums[0];
	for (int i = 1; i < count; ++i) {
		if (max < nums[i]) {
			max = nums[i];
		}
	}
	return max;
}

int get_min(int *nums, int count) {
	int min = nums[0];
	for (int i = 1; i < count; ++i) {
		if (min > nums[i]) {
			min = nums[i];
		}
	}
	return min;
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

	printf("Largest element: %d\n", get_max(nums, count));
	printf("Smallest element: %d\n", get_min(nums, count));
	free(nums);
	return 0;
}
