#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))
#define UNSET -1

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
void finding_pair_unsorted(int array[], int size, int target) {
    for(int i = 0; i < size - 1; i++) {
        for (int j = i+1; j < size; j++) {
            if(array[i] + array[j] == target) {
                printf("\n%d + %d = %d\n", array[i], array[j], target );
            }
        }
    }
}

// Time complexity O(N)
// Space complexity O(N)
void finding_pair_unsorted_hash(int array[], int size, int target) {
    int hash_array_size = highest_number(array, size);
    hash_array_size += 1; // to account for the highest number (zero index to highest number)
    int *hash_array = (int *)malloc(sizeof(int) * hash_array_size);
    for(int i = 0; i < hash_array_size; i++) {
        hash_array[i] = UNSET;
    }
    for(int i = 0; i < size; i++) {
        hash_array[array[i]]++;
        if(target-array[i] >= 0 && hash_array[target-array[i]] != UNSET) {
            printf("\n%d + %d = %d\n", array[i], target - array[i], target);
        }
    }
}

// Time complexity O(N)
// Space complexity O(1)
void finding_pair_sorted(int array[], int size, int target) {
    int i = 0; int j = size - 1;
    while (i < j)
    {
        if (array[i] + array[j] > target) {
            j--;
        } else if (array[i] + array[j] < target) {
            i++;
        } else {
            printf("\n%d + %d = %d\n", array[i], array[j], target);
            i++; j++;
        }
    }
}



int main() {

    int array_unsorted[] = {6,3,8,10,16,7,5,2,9,14};
    int array_sorted[] = {1,3,4,5,6,8,9,10,12,14};
    int target = 10;
    finding_pair_unsorted_hash(array_unsorted,ARRAY_SIZE(array_unsorted), target);
    finding_pair_unsorted(array_unsorted, ARRAY_SIZE(array_unsorted), target);
    finding_pair_sorted(array_sorted, ARRAY_SIZE(array_sorted), target);

    return 0;

}