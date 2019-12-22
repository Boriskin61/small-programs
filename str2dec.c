#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int sign = +1;
	char *num = 0;
    long long int res = 0;
    if (argc < 2) {
		return 0;
	}
    
	num = argv[1];
    if (*num == '-') {
		sign = -1;
		++num;
	} else if (*num == '+') {
		sign = +1;
		++num;
	}

	for (;*num; ++num) {
		if (*num >= '0' && *num <= '9') {
			res *= 10;
			res += (*num - '0');
		} else {
			return 0;
		}
	}
	printf(
		"String value is %s\n"
		"Decimial number is %lld\n", 
		argv[1], sign * res);
	return res;
}