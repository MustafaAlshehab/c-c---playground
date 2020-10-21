/* This applies to square matices n x n 

1 0 0
0 1 0
0 0 1

we may allocate an array of size n only to save space
instead of n * n size to store zeros
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int *matrix;
    int deminsions;
} diagonal_t;

void set(diagonal_t *matrix_ptr, int i, int j, int input) {
    if (i == j) {
        matrix_ptr->matrix[i] = input;
    }
}

int get(diagonal_t *matrix_ptr, int i, int j) {
    if (i == j) {
        return matrix_ptr->matrix[i];
    } else {
        return 0;
    }
}

void display(diagonal_t *matrix_ptr) {
    for(int i = 0; i < matrix_ptr->deminsions; i++) {
        for(int j = 0; j < matrix_ptr->deminsions; j++) {
            if (i == j)
            {
                printf("%d ", matrix_ptr->matrix[i]);
            } else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main() {
    diagonal_t matrix1;
    matrix1.deminsions = 5;
    matrix1.matrix = (int *)malloc(sizeof(int) * matrix1.deminsions);
    if(!matrix1.matrix) {
        printf("\nError: failed to allocate memroy\n");
    }

    srand(time(0));

    for(int i = 0; i < matrix1.deminsions; i++) {
        set(&matrix1, i, i, (rand() % 99) + 1);
    }

    display(&matrix1);

    free(matrix1.matrix);

    return 0;
}