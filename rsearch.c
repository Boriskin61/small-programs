#include <stdio.h>
#include <string.h>

int rsearch(char ch, const char *str, int pos) {
    return str[pos] == ch ? pos : str[pos] != '\0' ? rsearch(ch, str, pos + 1) : -1; 
}

int main(int argc, char* argv[]) {
	char ch, *str;
	int len, pos, count;
	if (argc < 1) {
		return 1;
	} else if (strlen(argv[1]) < 3 || argv[1][0] == ' ' || argv[1][1] != ' ') {
		printf("Unascceptable input. Input format must be \"<char> <string>\"\n");
		return 2;
	} else {
		count = 0;
		str = &argv[1][2];
		ch = argv[1][0];
		len = strlen(str);
	}

	pos = rsearch(ch, str, 0);
	if (pos >= 0) {
		++count;
		printf("The char %c is found at the positions [%d", ch, pos);
	}

	while ((pos = rsearch(ch, str, pos + 1)) >= 0) {
		printf(", %d", pos);
	}

	if (count) {
		printf("]\n");
	} else {
		printf("The char %c is not found\n", ch);
	}
	return 0;
}
