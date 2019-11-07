#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 1) {
		return 1;
	}

	int len = strlen(argv[1]);
	char ch, *str;
	if (len < 3 || argv[1][0] == ' ' || argv[1][1] != ' ') {
		printf("Unascceptable input. Input format must be \"<char> <string>\"\n");
		return 2;
	} else {
		str = argv[1];
		ch = argv[1][0];
	}

	printf("Search for %c\n", ch);
	for (int i = 0; i < len; ++i) {
		if (str[i] == ch) {
			printf("The char %c is found in %s at the position = %d\n", ch, str, i);
			return 0;
		}
	}
	
	printf("The number %d is not in the list\n", ch);
	return 0;
}
