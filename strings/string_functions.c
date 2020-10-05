#include <stdio.h>
#include <stdlib.h>

// Time complexity O(N)
// Space complexity O(1)
unsigned strlen_clone(const char *string) {
    unsigned length = 0;
    while(string[length] != '\0') {
        length++;
    }
    return length;
}
// Time complexity O(N)
// Space complexity O(1)
void change_case_of_string(char * string) {
    int diff = 'a' - 'A'; // 97 - 65 ascii value
    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i]>= 'a' && string[i] <= 'z') {
            string[i] -= diff;
        } else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += diff;
        }
    }
}

// Time complexity O(N)
// Space complexity O(1)
void words_vowels_consonant_count(const char *string) {
    int words_count = 0, vowels_count = 0, consonant_count = 0, last_visited_index = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        char ch = string[i];
        if(ch == 'a' || ch == 'A'
        || ch == 'e' || ch == 'E'
        || ch == 'i' || ch == 'I'
        || ch == 'o' || ch == 'O'
        || ch == 'u' || ch == 'U') {
            vowels_count++;
            last_visited_index = ch;
        } else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            consonant_count++;
            last_visited_index = ch;
        } else if (ch == ' ') {
            if(last_visited_index != 0 && last_visited_index != ' ') {
                words_count++;
                last_visited_index = ch;
            }
        }
        last_visited_index = ch;
    }
    if (last_visited_index != 0 && last_visited_index != ' ') {
        words_count++;
    }
    printf("words count: %d\nvowels count: %d\nconsonant count: %d\n", words_count, vowels_count, consonant_count);
}

// Time complexity O(N)
// Space complexity O(1)
//accept only alphapets and numbers
int validate_user_name(const char *string) {
    for(int i = 0; string[i] != '\0'; i++) {
        if(!(string[i] >= 'a' && string[i] <= 'z') 
        && !(string[i] >= 'A' && string[i] <= 'Z')
        && !(string[i] >= '0' && string[i] <= '9'))
        {
            return 0;
        }
    }
    return 1;
}

// Time complexity O(N)
// Space complexity O(N)
char *reverse_string1(const char *string) {
    int length = strlen_clone(string);
    char *reverse_string = (char *)malloc(sizeof(char) * length + 1);
    for(int i = 0, j = length - 1; i < length; i++, j--) {
        reverse_string[i] = string[j];
    }
    reverse_string[length] = '\0';

    return reverse_string;
}

// Time complexity O(N)
// Space complexity O(1)
void reverse_string2(char *string) {
    int length = strlen_clone(string);
    for(int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}

int main()
{
    char string1[] = "This   string is being used to test some string functionalities!";
    char string2[] = "            %$ ";
    char user_name[] = "BAADA555";
    char user_name2[] = "TheBeast!";
    printf("string1: %s\n", string1);
    printf("string1 length: %d\n", strlen_clone(string1));
    printf("string2: %s\n", string2);
    printf("string2 length: %d\n", strlen_clone(string2));
    change_case_of_string(string1);
    printf("%s\n", string1);
    printf("\nstring 1 count test\n");
    words_vowels_consonant_count(string1);
    printf("\nstring 2 count test\n");
    words_vowels_consonant_count(string2);

    if(validate_user_name(user_name)) {
        printf("\n%s is valid user name\n", user_name);
    } else {
        printf("\n%s is invalid user name\n", user_name);
    }

    if(validate_user_name(user_name2)) {
        printf("\n%s is valid user name\n", user_name2);
    } else {
        printf("\n%s is invalid user name\n", user_name2);
    }
    char *rev1 = reverse_string1(user_name);
    printf("\nreverse string is: %s\n", rev1);
    free(rev1);
    
    reverse_string2(string1);

    printf("\nstring1 reversal: %s\n", string1);

    return 0;
}