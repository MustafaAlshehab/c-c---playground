#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

// Time complexity O(N)
// Space O(1)
// this will work with multiple missing numbers, numbers could
// also starts from 0 or any other number as well
// example input {2,3,4,5,6,9,11,13}
void find_missing_elements_sorted(int array[], int size) {
    int current_diff = array[0];
    for(int i = 1; i < size; i++) {
        int index_diff = array[i] - i;
        if (index_diff != current_diff) {
            int offset = index_diff - current_diff;
            current_diff += offset;
            while (offset) {
                printf("%d ", array[i] - offset);
                offset--;
            }
        }
    }
    printf("\n\n");
}

// Time complexity O(N^2)
// Space O(1)
// this will work with multiple missing numbers
// example input {9,6,4,2,3,5,7,0,1}
void find_missing_elements_unsorted(int array[], int size) {
    int max_number = array[0];
    for(int i = 0; i < size; i++) {
        if ( array[i] > max_number) {
            max_number = array[i];
        }
    }

    for(int i = 0; i < max_number; i++) {
        int missing_element = 1;
        for(int j = 0; j < size; j++) {
            if(array[j] == i) {
                missing_element = 0;
                break;
            }
        }
        if (missing_element) {
            printf("%d ", i);
        }
    }
    printf("\n\n");
}

// Time complexity O(N)
// Space O(N+missing elements) 
// will use more space as we are using hashing
// this will work with multiple missing numbers
// example input {9,6,4,2,3,5,7,0,1}
void find_missing_elements_unsorted2(int array[], int size) {
    int max_number = array[0];
    for(int i = 0; i < size; i++) {
        if ( array[i] > max_number) {
            max_number = array[i];
        }
    }
    int * hash = (int *)malloc(sizeof(int) * max_number);

    for(int i = 0; i < max_number; i++) {
        hash[i] = 0;
    }

    for(int i = 0; i < size; i++) {
        hash[array[i]]++;
    }

    for(int i = 0; i < max_number; i++) {
        if(hash[i] == 0) {
            printf("%d ", i);
        }
    }

    printf("\n\n");
}

int main() {
    int array_sorted[] = {2,3,4,5,6,9,11,13};
    int array_unsorted[] = {9,6,4,2,3,5,7,0,1,20};

    find_missing_elements_sorted(array_sorted,ARRAY_SIZE(array_sorted));
    find_missing_elements_unsorted(array_unsorted,ARRAY_SIZE(array_unsorted));
    find_missing_elements_unsorted2(array_unsorted,ARRAY_SIZE(array_unsorted));


    return 0;
}