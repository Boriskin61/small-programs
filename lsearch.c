#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char ch, *str;
	int len, count;
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

	for (int i = 0; i < len; ++i) {
		if (str[i] == ch) {
			if (!count) {
				printf("The char %c is found at the positions = [%d", ch, i);
			} else {
				printf(", %d", i);
			}
			++count;
		}
	}
	
	if (count) {
		printf("]\n");
	} else {
		printf("The char %c is not found\n", ch);
	}
	return 0;
}
