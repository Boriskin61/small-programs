#include <stdio.h>
#include <string.h>

int checkForNumber(const char *num) {
	for (; *num; ++num) {
		if (*num < '0' || *num > '9') {
			return 0;
		}
	}
	return 1;
}

unsigned int findsum(const char *str) {
	return *str == '\0' ? 0 : *str + findsum(str + 1) - '0';
}

int main(int argc, char* argv[]) {
	char *str = NULL;
	unsigned int sum = 0;
	if (argc < 2) {
		return 1;
	} else if (!checkForNumber(argv[1])) {
		return 2;
	} else {
		str = argv[1];
		sum = findsum(argv[1]);
		printf("Sum is: %d\n", sum);
		return 0;
	}
}
