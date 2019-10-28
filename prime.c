#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
  if (argc < 2) 
    return 1;
  
  int n, flag = 0;
  n = strtol(argv[1], NULL, 10);
  for(int i = 2; i <= n/2; ++i) {
      if(n%i==0) {
          flag=1;
          break;
      }
  }

  if (flag==0)
      printf("%d is a prime number.\n",n);
  else
      printf("%d is not a prime number.\n",n);
  return 0;
}
