#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) { 
    int n1, n2, hcf = 1;
    if (argc < 2) {
        return 1;
    }
    sscanf(argv[1], "%d %d", &n1, &n2);
    for (int i = 1; i <= n1 || i <= n2; ++i) {
        hcf = n1%i || n2%i ? hcf : i;
    }
    printf("Highest Common Factor of %d and %d is %d\n", n1, n2, hcf);
    return 0;
}