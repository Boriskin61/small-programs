#include <stdio.h>
#include <stdlib.h>

long long int str2lli(const char *str) {
    long long int res = 0;
    while (*str) {
        res += *str++;
    }
    return res;
}

int main(int argc, char* argv[]) {
	long long int sum;
	if (argc < 2) {
		return 1;
	}

	long long int n = str2lli(argv[1]); 
	if (n < 0) {
		return 2;
	} else if (n == 0) {
		return 3;
	} else if (n < 6)  {
		sum = n - 1;
	} else if (n == 6) {
		sum = n;
	} else if (n % 2) {
		sum = n - 1;
	} else {
		sum = n / 2 + 2 + 1;
		for (int i = 3; i < n/2; ++i) {
			if (n % i == 0) {
				sum += i;
			}
		}
	}

	printf("%lld is %sperfect number %lld\n", n, sum == n ? "" : "not ", sum);
	return 0;
}
