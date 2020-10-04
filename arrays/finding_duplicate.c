#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
#define INVALID -1

int highest_number(int array[], int size) {
    int highest_number = array[0];
    for(int i = 1; i < size; i++) {
        if(array[i] > highest_number) {
            highest_number = array[i];
        }
    }
    return highest_number;
}

// Time complexity O(N^2)
// Space complexity O(1)
void finding_duplicate_unsorted(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int counter = 1;
        if (array[i] != INVALID) {
            for (int j = i+1; j < size; j++) {
                if(array[i] == array[j]) {
                    counter++;
                    array[j] = INVALID;
                }
            }
        }
        if (counter > 1) {
            printf("\nThe number %d is repeated %d times\n", array[i], counter);
        }
    }
}

// Time complexity O(N)
// Space complexity O(N)
void finding_duplicate_unsorted_hash(int array[], int size) {
    int hash_array_size = highest_number(array, size);
    hash_array_size += 1; // to account for the highest number (zero index to highest number)
    int *hash_array = (int *)malloc(sizeof(int) * hash_array_size);
    for(int i = 0; i < hash_array_size; i++) {
        hash_array[i] = 0;
    }
    for(int i = 0; i < size; i++) {
        hash_array[array[i]]++;
    }
    for(int i = 0; i < hash_array_size; i++) {
        if(hash_array[i] > 1) {
            printf("\nThe number %d is repeated %d times\n", i, hash_array[i]);
        }
    }
}


// Time complexity O(N)
// Space complexity O(1)
void finding_duplicate_sorted(int array[], int size) {
    for(int i = 0; i < size - 1; i++) {
        if (array[i] == array[i+1]) {
            int counter = 2;
            int j = i+1;
            while(array[i] == array[j+1]) {
                counter++;
                j++;
            }
            printf("\nThe number %d is repeated %d times\n", array[i], counter);
            i = j;
        }
    }
}

int main() {

    int array_unsorted[] = {1,1,2,1,100,201,100};
    int array_sorted[] = {1,1,1,2,8,9,10,10,101,102,102};
    finding_duplicate_unsorted_hash(array_unsorted,ARRAY_SIZE(array_unsorted));
    finding_duplicate_unsorted(array_unsorted, ARRAY_SIZE(array_unsorted));
    finding_duplicate_sorted(array_sorted, ARRAY_SIZE(array_sorted));

    return 0;

}