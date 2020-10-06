#include <stdio.h>
#include <string.h>

int strcmp_clone(const char *string1, const char *string2) {
    int i = 0;
    for(; string1[i] != '\0'; i++) {
        if(string1[i] > string2[i]) {
            return 1;
        } 
        else if (string1[i] < string2[i]) {
            return -1;
        }
    }
    if(string2[i] != '\0') {
        return -1;
    }

    return 0;
}

int main () {
   char str1[] = "abcdef";
   char str2[] = "abcde";

   int ret = strcmp_clone(str1, str2);

   if(ret < 0) {
      printf("str1 is less than str2\n");
   } else if(ret > 0) {
      printf("str1 is bigger than str1\n");
   } else {
      printf("str1 is equal to str2\n");
   }
   
   return 0;
}