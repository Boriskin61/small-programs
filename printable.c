#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *line;
	int i, print, digs, chars, other, len;
	if (argc < 2) {
		return 1;
	} else {
		line = argv[1];
		print = 0, digs = 0, chars = 0, other = 0, len = strlen(line);
	}

	for (i = 0; i < len; ++i) {
        if ((line[i]>='a' && line[i]<='z') || (line[i]>='A' && line[i]<='Z')) {
            ++chars; ++print;
        } else if ((line[i] >= '0' && line[i] <= '9')) {
            ++digs; ++print;
        } else if (line[i] >= ' ' && line[i] <= '\x7f') {
            ++other; ++print;
        }
	}

	printf(
        "Printable: %d\n"
        "Characters: %d\n"
        "Digits: %d\n"
        "Other printable: %d\n",
        print, chars, digs, other
    );
	return 0;
}
