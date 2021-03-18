#include <stdio.h>
#include <string.h>

#define VISITED_INDEX '/'
#define FOUND 1
#define NOT_FOUND 0

// Time complexity O(N)
// Space complexity O(1)
// accepts only small case letters
int is_anagram_hash(const char *str1, const char *str2) {
    if(strlen(str1) != strlen(str2)) {
        return 0;
    }

    int hash[25] = {0};

    for(int i = 0; str1[i] != '\0' ; i++) {
        hash[str1[i] - 97]++;
    }

    for(int i = 0; str2[i] != '\0'; i++) {
        hash[str2[i] - 97]--;
        if(hash[str2[i] - 97] < 0) {
            return 0;
        }
    }

    return 1;
}

// Time complexity O(N^2)
// Space complexity O(1)
int is_anagram(char *str1, char *str2) {
    if(strlen(str1) != strlen(str2)) {
        return 0;
    }
    for(int i = 0; str1[i] != '\0'; i++) {
        int flag = NOT_FOUND;
        for(int j = 0; str2[j] != '\0'; j++) {
            if(str1[i] == str2[j] && str2[j] != VISITED_INDEX) {
                flag = FOUND;
                str2[j] = VISITED_INDEX;
                break;
            }  
        }
        if(!flag) {
            return 0;
        }
    }
    return 1;
}


int main() {
    char str1[] = "listen";
    char str2[] = "silent";

    if(is_anagram_hash(str1,str2)) {
        printf("%s and %s are anagram!\n", str1, str2);
    } else {
        printf("%s and %s are NOT anagram.\n", str1, str2);
    }

    if(is_anagram(str1,str2)) {
        printf("%s and %s are anagram!\n", str1, str2);
    } else {
        printf("%s and %s are NOT anagram.\n", str1, str2);
    }
 
    return 0;
}