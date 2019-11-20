#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	} else {
		int res = 0;
		char *num = argv[1];
		for (int i = 0, len = strlen(num); i < len; ++i) {
			unsigned int n = num[i];
			res += n;
		}
		printf("Sum is: %d\n", res);
		return 0;
	}
}