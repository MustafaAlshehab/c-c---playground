#include <stdio.h>
#include <string.h>

// Time complexity O(N)
// Space complexity O(1)
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

// Time complexity O(N)
// Space complexity O(1)
int strcmp_clone2(const char *string1, const char *string2) {
    int i = 0;
    for(; string1[i] != '\0'; i++) {
        if(string1[i] != string2[i]) {
            break;
        }
    }
        if(string1[i] > string2[i]) {
            return 1;
        } 
        else if (string1[i] < string2[i]) {
            return -1;
        } else {
            return 0;
        }
}

// Time complexity O(N)
// Space complexity O(1)
int is_palindrome(const char *string) {
    int length = strlen(string);
    for(int i = 0, j = length - 1; i < j; i++, j--) {
        if(string[i] != string[j]) {
            return 0;
        }
    }
    return 1;
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

   char *str3[] = {"little", "noon", "level"};

   for(int i = 0; i < 3; i++) {
       if(is_palindrome(str3[i])) {
           printf("%s is a palindrome\n", str3[i]);
       } else {
           printf("%s is NOT a palindrome\n", str3[i]);
       }
   }
   return 0;
}