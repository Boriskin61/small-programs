#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parseArg(char *argv1, char **res, int **count) {
	int len = strlen(argv1);
	int c = argv1[0] != ' ';

	for (int i = 0; i < len; ++i) {
		c += argv1[i] == ' ' && argv1[i + 1] != ' ';
	}

	*res = calloc(c, sizeof(char *));
	if (*res == NULL) {
		return 1;
	}

	for (int i = 1; i < len; ++i) {
		if (argv1[i] == ' ' && argv1[i + 1] != ' ') {

		}
	}
}

int stringCompare(const char *str1, const char *str2){
     while (*str1++ != '\0' && *str2++ != '\0') {
          if (*str1 != *str2) {
			  return 0;
          }
     }
	 return 1;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	char* str1 = argv[1], str2;
	int compare, len = strlen(str1);
	for (int i = 1; i < len; ++i) {
		if (str1[i] == ' ') {
			str1[i] = '\0';
			if (str1[i + 1] != ' ') {
				str2 = &str1[i + 1];
			}
		}
	}

	if (stringCompare(str1, str2)) {
		printf("Both strings are equal.");
	} else {
		printf("Both strings are not equal");
	}
	return 0;
}
