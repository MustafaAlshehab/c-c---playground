#include <stdio.h>
#include <string.h>

#define UNAVAILABLE 1
#define AVAILABLE 0

void str_permutation(const char *str, int tree_level) {
    int str_length = strlen(str);
    static char result[100] = {0};
    static int index_status[100] = {0};

    if(str[tree_level] == '\0') {
        result[tree_level] = '\0';
        printf("%s\n", result);
    } else {
        for(int i = 0; str[i] != '\0'; i++) {
            if(index_status[i] == AVAILABLE) {
                result[tree_level] = str[i];
                index_status[i] = UNAVAILABLE;
                str_permutation(str,tree_level+1);
                index_status[i] = AVAILABLE;
            }
        }
    }
}

int main() {
    char str1[] = "ABC";
    str_permutation(str1,0);
    
    return 0;
}