/*
permutation of a string is every arrangement of such a string
which is n! where n is characters count
Topics I went through:
    - Back Tracking
    - State Space Tree
*/

#include <stdio.h>
#include <string.h>

#define UNAVAILABLE 1
#define AVAILABLE 0
#define SIZE 30

// Time complexity O(N*N!)
// Space complexity O(N)
void str_permutation(const char *str, int tree_level) {
    if(strlen(str) > SIZE) {
        printf("string is too long\n");
        return;
    }
    static char result[SIZE] = {0};
    static int index_status[SIZE] = {0};

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

void swap(char *x, char *y) {
    char temp = *x;
    *x= *y;
    *y = temp;
} 

// Time complexity O(N*N!)
// Space complexity O(N)
void str_permutation_2(char *str, int tree_level, int highest_tree_level) {

    if(tree_level == highest_tree_level) {
        printf("%s\n", str);
    } else {
        for(int i = tree_level; str[i] != '\0'; i++) {
            swap(&str[tree_level], &str[i]);
            str_permutation_2(str,tree_level+1,highest_tree_level);
            swap(&str[i], &str[tree_level]);
        }
    }
}

int main() {
    char str1[] = "ABC";
    //str_permutation(str1,0);
    str_permutation_2(str1,0,strlen(str1));
    
    return 0;
}