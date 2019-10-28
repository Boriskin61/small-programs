#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int *x, int first, int last) {
  int pivot, j, temp, i;
  if (first<last) {
    pivot=first;
    i=first;
    j=last;

    while (i < j) {
      while(x[i] <= x[pivot] && i < last)
        i++;
      while(x[j] > x[pivot])
        j--;
      if(i < j) {
        temp=x[i];
        x[i]=x[j];
        x[j]=temp;
      }
    }

    temp=x[pivot];
    x[pivot]=x[j];
    x[j]=temp;
    quicksort(x,first,j-1);
    quicksort(x,j+1,last);
  }
}

int main(int argc, char* argv[]) {
  char *next;
  int i, count, *nums;
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

  quicksort(nums, 0, count - 1);
  printf("Sorted elements: ");
  for(int i = 0; i < count; ++i) {
    printf(" %d", nums[i]);
  }
  printf("\n");
  
  free(nums);
  return 0;
}
