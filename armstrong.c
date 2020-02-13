#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pow3[] = { 0, 1, 8, 27, 64, 125, 216, 343, 512, 729 };

int main(int argc, char* argv[]) {
  long long n;
  if(argc < 2) {
    return 1;
  } else {
    n = atoll(argv[1]);
  }

  if (n == 0) {
    return 2;
  }

  int num, arm = 0, len = strlen(argv[1]);
  for (int i = 0; i < len; ++i) {
    if (argv[1][i] >= '0' && argv[1][i] <= '9') {
      arm += pow3[argv[1][i] - '0'];
    } else {
      return 3;
    }
  }
  printf("%lld is %san Armstrong number\n", n, n == arm ? "" : "not ");
}
