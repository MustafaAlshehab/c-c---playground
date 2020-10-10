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

// Time complexity O(N)
// Space complexity O(1)
// The disadvantage of this method when compared to hash method 
// is that you cannot keep track of how many times a duplicate
// has occurred without allocating more space. But it uses much
// less space, tough, both are O(1) in terms of space
// this implementation covers only small case letter assuming 
// size of int is 4 bytes you may extend that by using long int 
void finding_duplicate_bitwise(const char *string) {
    int hash_bitwise = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            if(hash_bitwise & 1 << (string[i] - 97)) {
                printf("%c is duplicated\n", string[i]);
            }
            else {
                hash_bitwise |= 1 << (string[i] - 97); 
            }
        }
    }
}

int main()
{
    char str1[] = "hello world!!";
    finding_duplicate_hash(str1);
    finding_duplicate(str1);

    char str2[] = "hello, this is a test";
    finding_duplicate_bitwise(str2);

    return 0;
}