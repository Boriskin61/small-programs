#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }


  
  int temp,i,j,a[10];

  for(i = 1; i < argc; ++i) {
      a[i-1] = argv[i][0];
  }
  
  for(i=argc-3;i>=0;i--){
      for(j=0;j<=i;j++){
           if(a[j]>a[j+1]){
               temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           }
      }
  }

  printf("After sorting: ");
  for(i=0;i<argc-1;i++)
      printf(" %d",a[i]);

  return 0;
}
