#include <stdio.h>
#include <stdlib.h>

void swap1(int *a, int *b);

int main() {
    int x = 5;
    int y = 10;

    printf("Vlaues before swap x:%d y:%d\n", x, y);
    swap1(&x, &y);
    printf("Vlaues after swap 1 x:%d y:%d\n", x, y);

    return 0;
} 
void swap1(int *a, int *b) {
    int *temp = a;
    a = b;
    b = temp;
}
