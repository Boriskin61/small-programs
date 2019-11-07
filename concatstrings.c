#include <stdio.h>
#include <string.h>

void stringConcat(char *str1, const char *str2) {
	int i = 0, j = 0;

	for (; str1[i] != '\0'; ++i) { ; }
	while (str2[j] != '\0') {
		str1[i++] = str2[j++];
	}
	str1[i] = '\0';
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char* str1 = argv[1], *str2 = NULL;
	int len = strlen(str1);
	for (int i = 1; i < len; ++i) {
		if (str1[i] == ' ') {
			str1[i] = '\0';
			if (str1[i + 1] != ' ') {
				str2 = &str1[i + 1];
			}
		}
	}

	if (!str2) {
		printf("Invalid input. Try \"<string1> <string2>\"\n");
		return 2;
	}

	stringConcat(str1, str2);
	printf("String after concatenation: %s\n", str1);
	return 0;
}