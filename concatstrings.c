#include<stdio.h>

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

	char* str1 = argv[1];
	char* str2 = argv[2];
	stringConcat(str1, str2);

	printf("String after concatenation: %s \n", str1);

	return 0;
}