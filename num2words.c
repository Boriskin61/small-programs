#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	int len = strlen(argv[1]);

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
    
    for (int i = 0; i < len; ++i) {
        int num = argv[1][i] - '0';
        if (num >=0 && num <= 9) {
            printf("%s ", words[num]);
        } else {
			printf("\nError! Symbol '%c' is not a digit\n", argv[1][i]);
			return -1;
		}
	}
	printf("\n");
	return 0;
}
