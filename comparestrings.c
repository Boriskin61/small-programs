#include <stdio.h>
#include <stdlib.h>

int stringCompare(char[],char[]);
int main(int argc, char* argv[]){
     if (argc < 2) {
          return 1;
     }
     
     char* str1 = argv[1], str2;
     int compare, len = strlen(str1);
     for (int i = 1; i < len; ++i) {
          if (str1[i] == ' ') {
               str1[i] = '\0';
               if (str1[i + 1] != ' ') {
                    str2 = &str1[i + 1];
               }
          }
     }

     compare = stringCompare(str1, str2);
     if(compare == 1) {
          printf("Both strings are equal.");
     } else {
          printf("Both strings are not equal");
     }
     return 0;
}

int stringCompare(char str1[],char str2[]){
     int i, flag = 0;

     for (i = 0; str1[i] != '\0' && str2[i]!= '\0'; ++i) {
          if (str1[i] != str2[i]) {
               flag = 1;
               break;
          }
     }

     if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') {
          return 1;
     } else {
          return 0;
     }
}
