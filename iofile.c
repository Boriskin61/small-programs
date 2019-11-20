#include <stdio.h>

const char *filename = "program.txt";

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}

	FILE *wfile = fopen(filename, "w");
	if (wfile == NULL) {
		printf("Error to create file %s\n", filename);
		return 1;
	}

	fprintf(wfile, "%s ", argv[1]);
	fclose(wfile);

	FILE *rfile = fopen(filename, "r");
	if (rfile == NULL) {
		printf("Error to open file %s\n", filename);
		return 2;
	}

	char ch;
	while ((ch = fgetc(rfile)) != EOF) {
		printf("%c", ch);
	}
	printf("\n");
	fclose(rfile);
	
	if (remove(filename)) {
		printf("Error to delete file %s\n", filename);
	} else {
		printf("Done!");
	}
	
	return 0;
}
