#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	if (stringCompare(str1, str2)) {
		printf("Both strings are equal.");
	} else {
		printf("Both strings are not equal");
	}
	return 0;
}
