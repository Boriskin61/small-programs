#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _minmax_ {
	int min;
	int max;
} minmax;

minmax get_minmax(char *nums, int count) {
	minmax mm;
	mm.min = nums[0];
	mm.max = nums[0];
	for (int i = 1; i < count; ++i) {
		if (mm.min > nums[i]) {
			mm.min = nums[i];
		}
		if (mm.max < nums[i]) {
			mm.max = nums[i];
		}
	}
	return mm;
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

	minmax mm = get_minmax(nums, len);
	printf(
		"Largest element: %d\n"
		"Smallest element: %d\n", mm.max, mm.min);
	return 0;
}
