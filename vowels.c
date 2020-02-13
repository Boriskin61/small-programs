#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char *line;
	int i, v, c, d, w, len;
	if (argc < 2) {
		return 1;
	} else {
		line = argv[1];
		v = c = d = w = 0, len = strlen(line);
	}

	for (i = 0; i < len; ++i) {
        if (line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u' || line[i]=='A' || line[i]=='E' || line[i]=='I' || line[i]=='O' || line[i]=='U')
            ++v;
        else if ((line[i]>='a'&& line[i]<='z') || (line[i]>='A'&& line[i]<='Z'))
            ++c;
        else if (line[i]>='0'&&c<='9')
            ++d;
        else if (line[i]==' ')
            ++w;
	}

	printf(
		"Vowels: %d\n"
		"Consonants: %d\n"
		"Digits: %d\n"
		"White spaces: %d\n",
		v, c, d, w);
	return 0;
}
