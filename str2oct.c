#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char *num = 0;
    long long int res = 0;
    if (argc < 2) {
		return 1;
	} else if (argv[1][0] != '0') {
		return 2;
	}

	for (num = &argv[1][1]; *num; ++num) {
		if (*num >= '0' && *num <= '7') {
			res *= 8;
			res += (*num - '0');
		} else {
			return 3;
		}
	}
	printf(
		"String value is %s\n"
		"Decimial number is %llo\n", 
		argv[1], res);
	return 0;
}