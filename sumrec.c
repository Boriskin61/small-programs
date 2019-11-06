#include <stdio.h>
#include <stdlib.h>

int r,len ;

int findsum(int n) {
	if (n) {
		r = n % 10;
		len  += r;
		findsum(n / 10);
	} else {
		return len ;
	}
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		return 1;
	}
	int num, x;
	num = strtol(argv[1], NULL, 10);
	x = findsum(num);
	printf("Sum of the digits of %d is: %x\n", num, x);
	return 0;
}