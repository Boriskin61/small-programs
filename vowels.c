#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *line;
	int i, v, c, d, w, len;
	if (argc < 2) {
		return 1;
	} else {
		line = argv[1];
		i = v = c = d = w = 0, len = strlen(line);
	}

	for (i = 0; i < len; ++i) {
		switch (line[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			++v;
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			++d;
			break;
		case ' ':
			++w ;
			break;
		default:
			if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A'&& line[i] <= 'Z')) {
				++c;
			}
			break;
		}
	}

	printf(
		"Vowels: %d\n"
		"Consonants: %d\n"
		"Digits: %d\n"
		"White spaces: %d\n"
		, v, c, d, w);
	return 0;
}
