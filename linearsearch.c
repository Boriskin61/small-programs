#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char *next;
    int count, *nums;
    if (argc < 1) {
        return 1;
    }

    int len = strlen(argv[1]);
    for (int i = 0; i < len; ++i) {
        if ('0' <= argv[1][i] && argv[1][i] <= '9') {
            continue;
        } else if (argv[1][i] == ' ') {
            continue;
        } else {
            printf("Invalid number in input string: %c\n", argv[1][i]);
            return 2;
        }
    }

  
    next = argv[1];
    for (count = 0; strtol(next, &next, 10) || *next != '\0'; ++count) { ; }

    printf("numbers count = %d\n", count);
    nums = calloc(count, sizeof(int));
    if (!nums) {
        return 2;
    }

    next = argv[1];
    for (int i = 0; i < count; ++i) {
        nums[i] = strtol(next, &next, 10);
    }
    
    int fnd, min = nums[count - 1];
    printf("Search for %d\n", min);
    for (int i = 0; i < count-1; ++i) {
        if (nums[i] == min) {
            fnd = 1;
            break;
        }
    }

    if (fnd == 0) {
        printf("The number %d is not in the list\n", min);
    }
    else {
        printf("The number %d is found\n", min);
    }
    return 0;
}
