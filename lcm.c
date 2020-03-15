#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) { 
    int n1, n2, lcm;
    if (argc < 2) {
        return 1;
    }
    sscanf(argv[1], "%d %d", &n1, &n2);
    for (lcm = n1 > n2 ? n1 : n2; lcm%n1 || lcm%n2; ++lcm) { ; }
    printf("Low Common Multiple of %d and %d is %d\n", n1, n2,lcm);        
    return 0;
}

