#include <stdio.h>

int number_of_steps = 0;
int number_of_function_calls = 0;

// Time complexity O(2^n) specifically 2^(n+1) -1
// Space complexity O(n) specifically n+1
void TOH(int input, char A, char B, char C) {
    number_of_function_calls++;
    if(input > 0) {
        number_of_steps++;
        TOH(input - 1, A, C , B );
        printf("Move disk from tower %c to %c\n", A, C);
        TOH(input - 1, B, A, C);
    }

}

int main() {
    TOH(3,'A', 'B', 'C');
    printf("number of steps are %d\n", number_of_steps);
    printf("number of function_calls are %d\n", number_of_function_calls);
    return 0;
}