#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char *num = 0;
    long long int res = 0;
    if (argc < 2) {
		return 0;
	} else if (argv[1][0] != '0' || argv[1][1] != 'x') {
        return 0;
    }
    
	num = &argv[1][2];
	for (;*num; ++num) {
        res <<= 4;
		if (*num >= '0' && *num <= '9') {
			res += (*num - '0');
		} else if (*num >= 'A' && *num <= 'F') {
            res += (*num - 'A' + 10);
        } else if (*num >= 'a' && *num <= 'f') {
            res += (*num - 'a' + 10);
        } else {
			return 0;
		}
	}
	printf(
        "String value is %s\n"
        "Decimial number is %lld\n"
        "Hexadecimal number is %llx\n", 
        argv[1], res, res);
	return res;
}