#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if (argc < 2) {
    return 1;
  }
  
  long int decimalNumber,remainder,quotient;
  int octalNumber[32],i,j;
  
  decimalNumber = atol(argv[1]);
  quotient = decimalNumber;

  for (i = 0; quotient != 0; ++i) {
      octalNumber[i]= quotient % 8;
      quotient = quotient / 8;
  }

  printf("Equivalent octal value of decimal number %ld is ", decimalNumber);
  for (j = i - 1; j >= 0; --j)
    printf("%d",octalNumber[j]);
  printf("\n");
  return 0;
}
