#include <stdio.h>
#include <string.h>

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

	int c = 0, l = 0, u = len - 1;
	while (l <= u) {
		int mid = (l + u) / 2;
		if (ch == str[mid]) {
			c = 1;
			break;
		} else if (ch < str[mid]) {
			u = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	if (c == 0) {
		printf("The number is not found.\n");
	} else {
		printf("The number is found.\n");
	}
	return 0;
}
