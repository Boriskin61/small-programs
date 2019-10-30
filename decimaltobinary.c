#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc < 2) {
        return 1;
    }

    long int decimalNumber, remainder, quotient;
    int binaryNumber[64], i, j;

    decimalNumber = atol(argv[1]);
    quotient = decimalNumber;


    for (i = 0; quotient != 0; ++i) {
        binaryNumber[i]= quotient % 2;
        quotient = quotient / 2;
    }

    printf("Equivalent binary value of decimal number %ld is ", decimalNumber);
    for (j = i - 1; j >= 0; j--) {
        printf("%d",binaryNumber[j]);
    }
    printf("\n");
    return 0;
}
