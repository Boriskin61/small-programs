#include <stdio.h>
#include <string.h>

int binary(char sorted[], int n, int m, int l, int u) {
	int mid, c = 0;

	if (l <= u) {
		mid = (l + u) / 2;
		if (m == sorted[mid]) {
			return 1;
		} else if (m < sorted[mid]) {
			return binary(sorted, n, m, l, mid - 1);
		} else {
			return binary(sorted, n, m, mid + 1, u);
		}
	} else {
		return 0;
	}
}

int main(int argc, char* argv[]) {
	int len;
	if (argc < 2) {
		return 1;
	} else {
		len = strlen(argv[1]);
	}

	char ch, *str;
	if (len < 3 || argv[1][0] == ' ' || argv[1][1] != ' ') {
		printf("Unascceptable input. Input format must be \"<char> <string>\"\n");
		return 2;
	} else {
		len -= 2;
		ch = argv[1][0];
		str = &argv[1][2];
	}

	if (binary(str, len - 1, ch, 0, len - 2)) {
		printf("Number is found.\n");
	} else {
		printf("Number is not found.\n");
	}

	return 0;
}

