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

unsigned long long int findmul(const char *str) {
	return *str == '\0' ? 1 : findmul(str + 1) * (*str - '0');
}

int main(int argc, char* argv[]) {
	char *str = NULL;
	unsigned long long mul = 0;
	if (argc < 2) {
		return 1;
	} else if (!checkForNumber(argv[1])) {
		return 2;	
	} else {
        str = argv[1];
		mul = findmul(str);
        printf("Mul is: %llu\n", mul);
		return 0;
	}
}