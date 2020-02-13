#include <stdio.h>
#include <string.h>

char** getWords() {
    static char* words[10];
    words[0] = "zero";
    words[1] = "one";
    words[2] = "two";
    words[3] = "three";
    words[4] = "four";
    words[5] = "five";
    words[6] = "six";
    words[7] = "seven"; 
    words[8] = "eight"; 
    words[9] = "nine";
    return words;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int i, len = strlen(argv[1]);
    char **words = getWords();
	for (i = 0; i < len; ++i) {
        if (argv[1][i] < '0' && '9' < argv[1][i]) {
			printf("Error! Symbol '%c' is not a digit\n", argv[1][i]);
			return -1;
		}
        printf("%s ", words[argv[1][i] - '0']);
	}
	printf("\n");
	return 0;
}
