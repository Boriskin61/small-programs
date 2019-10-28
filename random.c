#include <time.h>
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[]) {
  int c, n, x;
  if (argc < 2) {
    return 1;
  }
  x = strtol(argv[1], NULL, 10);
  
  srand(time(NULL));
  printf("%d random numbers in [1,100]\n", x);
  for (c = 1; c <= x; c++) {
    n = rand() % 100 + 1;
    printf("%d\n", n);
  }
  return 0;
}
