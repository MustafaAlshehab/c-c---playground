#include <stdio.h>

#define DUPLICATE_FLAG '/'

// Time complexity O(N^2)
// Space complexity O(1)
void finding_duplicate(char *string) {
    int count;
    for(int i = 0; string[i] != '\0'; i++) {
        count = 0;
        for(int j = i + 1; string[j] != '\0'; j++) {
            if (string[j] != DUPLICATE_FLAG)  {
                if(string[i] == string[j]) {
                    count++;
                    string[j] = DUPLICATE_FLAG;
                }
            }
        }
        if(count > 0) {
            printf("%d duplicate(s) of %c\n", count, string[i]);
        }
    }
}

// Time complexity O(N)
// Space complexity O(1)
void finding_duplicate_hash(const char *string) {
    int hash[96] = {0};
    int hash_length = sizeof(hash) / sizeof(hash[0]);
    for(int i = 0; string[i] != '\0'; i++) {
        hash[string[i] - 32]++;
    }
    for(int i = 0; i < hash_length; i++) {
        if(hash[i] > 1) {
            printf("%d duplicate(s) of %c\n", hash[i] - 1, i+32);
        }
    }   
}

int main()
{
    char str1[] = "hello world!!";
    finding_duplicate_hash(str1);
    finding_duplicate(str1);

    return 0;
}