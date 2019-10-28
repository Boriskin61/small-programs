#include<stdio.h>

int isNull(char c) {
   return c == '\0';
}

int isDigit(char c) {
   return (c >= '0' && c <= '9');
}

int isLatinLetter(char c) {
   return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(int argc, char* argv[]){
   if (argc < 2) {
      return 1;
   }
   char* str = argv[1];
   do {
      for (; !isDigit(*str) && !isLatinLetter(*str) && !isNull(*str); ++str) { ; }
      if (isNull(*str))
         break;
      else 
         printf("%c ", *str);
      for (; isDigit(*str) || isLatinLetter(*str) || isNull(*str); ++str) { ; }
   } while (!isNull(*str));
   printf("\n");
   return 0;
}
