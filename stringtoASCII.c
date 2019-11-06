#include <stdio.h>

int main(int argc, char* argv[]) {
	int i = 0;
	char *str = NULL;
	if (argc < 2) {
		return 1;
	} else {
		str = argv[1];
	}

	printf("ASCII values of each characters of given string: ");
	while (str[i]) {
		printf("%d ", str[i++]);
	}
	printf("\n");
	return 0;
}
