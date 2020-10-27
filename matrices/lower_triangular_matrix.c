/* This applies to square matices n x n 

1 0 0
1 1 0
1 1 1

we may allocate an array of size n(n+1)/2 only to save space
which is the formula of the sum of natural number instead 
of n * n size to store zeros. This program uses row-major mapping
to map values correctly as it should on a 2d array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int *matrix;
    int deminsions;
} lower_triangular_t;

void set(lower_triangular_t *matrix_ptr, int i, int j, int input) {
    int index = 0;
    if (i >= j) {
        index = i*(i+1)/2 + j;
        matrix_ptr->matrix[index] = input;
    }
}

int get(lower_triangular_t *matrix_ptr, int i, int j) {
    int index = 0;
    if (i >= j) {
        index = i*(i+1)/2 + j;
        return matrix_ptr->matrix[index];
    } else {
        return 0;
    }
}

void display(lower_triangular_t *matrix_ptr) {
    int index = 0;
    for(int i = 0; i < matrix_ptr->deminsions; i++) {
        for(int j = 0; j < matrix_ptr->deminsions; j++) {
            if (i >= j)
            {
                index = i*(i+1)/2 + j;
                printf("%d ", matrix_ptr->matrix[index]);
            } else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}

int main() {
    lower_triangular_t matrix1;
    matrix1.deminsions = 5;
    int size = matrix1.deminsions * (matrix1.deminsions + 1) / 2;
    matrix1.matrix = (int *)malloc(sizeof(int) * size);
    if(!matrix1.matrix) {
        printf("\nError: failed to allocate memroy\n");
    }

    srand(time(0));

    for(int i = 0; i < matrix1.deminsions; i++) {
        for(int j = 0; j < matrix1.deminsions; j++) {
            if (i >= j) {
                set(&matrix1, i, j, (rand() % 99) + 1);
            }
        }
    }

    display(&matrix1);

    free(matrix1.matrix);

    return 0;
}