#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int i, len = strlen(argv[1]);
	char *word[32];

	for (i = 0; i < len; ) {
		switch (argv[1][i]) {
		case '0': 
			word[i++] = "zero";
			break;
		case '1': 
			word[i++] = "one";
			break;
		case '2': 
			word[i++] = "two";
			break;
		case '3': 
			word[i++] = "three";
			break;
		case '4': 
			word[i++] = "four";
			break;
		case '5': 
			word[i++] = "five";
			break;
		case '6': 
			word[i++] = "six";
			break;
		case '7': 
			word[i++] = "seven"; 
			break;
		case '8': 
			word[i++] = "eight"; 
			break;
		case '9': 
			word[i++] = "nine";
			break;
		default:
			printf("Error! Symbol '%c' is not a digit\n", argv[1][i++]);
			return -1;
		}
	}

	for (int j = i - 1; j >= 0; --j) {
		printf("%s ", word[j]);
	}
	printf("\n");
	return 0;
}
