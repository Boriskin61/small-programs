#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *line;
	int i, v, len;
	if (argc < 2) {
		return 1;
	} else {
		line = argv[1];
		v = 0, len = strlen(line);
	}

	for (i = 0; i < len; ++i) {
        if (line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='y'
		|| line[i]=='A' || line[i]=='E' || line[i]=='I' || line[i]=='O' || line[i]=='U' || line[i]=='Y') {
            ++v;
		}
	}

	printf("Vowels: %d\n", v);
	return 0;
}
