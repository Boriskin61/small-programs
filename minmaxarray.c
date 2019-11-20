#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_max(char *nums, int count) {
	int max = nums[0];
	for (int i = 1; i < count; ++i) {
		if (max < nums[i]) {
			max = nums[i];
		}
	}
	return max;
}

int get_min(char *nums, int count) {
	int min = nums[0];
	for (int i = 1; i < count; ++i) {
		if (min > nums[i]) {
			min = nums[i];
		}
	}
	return min;
}

int main(int argc, char* argv[]) {
	int len = 0;
	char *nums = 0;
	if (argc < 2) {
		return 1;
	} else {
		nums = argv[1];
		len = strlen(nums);
	}

	printf("Largest element: %d\n", get_max(nums, len));
	printf("Smallest element: %d\n", get_min(nums, len));
	free(nums);
	return 0;
}
