#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	} else {
		long long int res = 1;
        char *num = argv[1];
		for (int i = 0, len = strlen(num); i < len; ++i) {
			res *= num[i];
		}
		printf("Mul is: %lld\n", res);
		return 0;
	}
}