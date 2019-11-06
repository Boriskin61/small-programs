#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int count = 0;
	int len = strlen(argv[1]);
	char ch;
	if (len < 3 || argv[1][0] == ' ' || argv[1][1] != ' ') {
		printf("Unascceptable input. Input format must be \"<char> <string>\"\n");
	} else {
		ch = argv[1][0];
	}

	for (int i = 2; i < len; ++i) {
		count += ch == argv[1][i];
	}
	printf("Frequency of %c = %d", ch, count);
	return 0;
}
