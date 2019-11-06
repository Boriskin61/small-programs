#include <stdio.h>

int main(int argc, char* argv[]) {
	char *line = NULL;
	int i, v, c, ch, d, len , o;
	if (argc < 2) {
		return 1;
	} else {
		line = argv[1];
		i = v = c = ch = d = len  = o = 0;
	}

	for (i = 0; line[i] != '\0'; ++i) {
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
			++len ;
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
		, v, c, d, len );
	return 0;
}
