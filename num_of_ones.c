#include <stdio.h>

int main() {

    int x = 1;
    int counter = 0;

    while (x)
    {
        // or counter += x & 1;
        counter += x % 2;
        // or x >>= 1;
        x /= 2;
    }
    printf("number of ones is %d\n", counter);

    return 0;
}