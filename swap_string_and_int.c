/*
    ref: https://stackoverflow.com/questions/8403447/swapping-pointers-in-c-char-int
    when we want to swap char * we need a double pointer to pass the address of a pointer
    and swap the address of where is the pointer is pointing to, and we need double pointers 
    in that case. Whereas when we are swapping an int we need a pointer to to access tha 
    location of each int in memory and change the value.

    We use references in C++ for great success, Or std::swap
*/

#include <stdio.h>

void swap_str(const char **str1, const char**str2);
void swap_int(int *a, int *b);
int main() {

    const char *string1 = "This is string 1";
    const char *string2 = "This is string 2";
    printf("strings BEFORE swap:\nstring1: %s, string2: %s\n", string1, string2);
    swap_str(&string1, &string2);
    printf("strings AFTER swap:\nstring1: %s, string2: %s\n", string1, string2);

    int x = 5;
    int y = 10;
    printf("\nint BEFORE swap:\nint x: %d, int y: %d\n", x, y);
    swap_int(&x,&y);
    printf("int AFTER swap:\nint x: %d, int y: %d\n", x, y);
    return 0;
}
void swap_str(const char **str1, const char **str2) {
    const char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}