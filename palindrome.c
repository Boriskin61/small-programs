#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *str = argv[1];
	int result = 1;
	int len = strlen(str);
	for (int i = 0, end = len >> 1; result && i < end; ++i) {
		result &= str[i] == str[len - i - 1];
	}

	if (result) {
		printf("'%s' is palindrome\n", str);
	} else {
		printf("'%s' is not palindrome\n", str);
	}
	return 0;
}
