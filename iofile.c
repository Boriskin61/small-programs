#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	FILE *wfile = fopen("program.txt", "w");
	if (wfile == NULL) {
		printf("Error to create file %s \n", "program.txt");
		return 1;
	}

	fprintf(wfile, "%s ", argv[1]);
	fclose(wfile);

	FILE *rfile = fopen("program.txt", "r");
	if (rfile == NULL) {
		printf("Error to open file %s \n", "program.txt");
		return 2;
	}

	char ch;
	while ((ch = fgetc(rfile)) != EOF) {
		printf("%c", ch);
	}
	printf("\n");
	fclose(rfile);
	return 0;
}
