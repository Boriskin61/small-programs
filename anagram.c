#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_anagram(char sorted[], char b[]) {
	int first[26] = { 0 }, second[26] = { 0 }, c = 0;

	while (sorted[c] != '\0') {
		first[sorted[c] - 'a']++;
		c++;
	}

	c = 0;

	while (b[c] != '\0') {
		second[b[c] - 'a']++;
		c++;
	}

	for (c = 0; c < 26; c++) {
		if (first[c] != second[c]) {
			return 0;
		}
	}

	return 1;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		return 1;
	}

	char *fst = argv[1], *snd = NULL;
	int len = strlen(fst);

	for (int i = 1; i < len; ++i) {
		if (fst[i] == ' ') {
			fst[i] = '\0';

			if (!snd && (i + 1) < len && fst[i + 1] != ' ') {
				snd = &fst[++i];
			}
		}
	}

	if (!fst && !snd) {
		printf("Invalid input argument, try \"str1 str2\"\n");
		return 2;
	}

	if (check_anagram(fst, snd) == 1) {
		printf("\"%s \" and \"%s \" are anagrams.\n", fst, snd);
	} else {
		printf("\"%s \" and \"%s \" are not anagrams.\n", fst, snd);
	}

	return 0;
}