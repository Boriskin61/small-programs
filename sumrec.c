#include <stdio.h>
#include <stdlib.h>

int r,s;

int findsum(int n) {
  if (n) {
    r = n % 10;
    s += r;
    findsum(n/10);
  } else {
    return s;
  }
}

int main(int argc, char* argv[]){
  if (argc < 2) {
    return 1;
  }
  int num,x;
  num = strtol(argv[1], NULL, 10);
  x = findsum(num);
  printf("Sum of the digits of %d is: %x\n", num, x);
  return 0;
}