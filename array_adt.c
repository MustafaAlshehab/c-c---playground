#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
    int A[10];
    int size;
    int length;
}Array_t;

void display(Array_t *array) {
    if(array->length < 1) {
        printf("\nNo elements to display\n");
        return;
    }
    int i = 0;
    printf("\nArray elements: ");
    while(i < array->length) {
        printf("%d ", array->A[i]);
        i++;
    }
    printf("\n");
}

void insert(Array_t *array, int input, int index) {
    if (index < 0 || index > array->length) {
        printf("\nERROR: inserting index %d - index cannot be negative or greater than length\n", index);
        return;
    }
    int i = array->length;
    while (i > index)
    {
        array->A[i] = array->A[i-1];
        i--;
    }
    array->A[i] = input;
    array->length++;
}

void append(Array_t *array, int input) {
    if (array->length > array->size) {
        printf("\nERROR: there is no more avaliable space to store %d in the array\n", input);
        return;
    }
    array->A[array->length] = input;
    array->length++;
}

void delete(Array_t *array, int index) {
    if (index < 0 || index > array->length) {
        printf("\nERROR: Deleting index %d - index cannot be negative or greater than length\n", index);
        return;
    }

    int i = index;
    while (i < array->length - 1)
    {
        array->A[i] = array->A[i+1];
        i++;
    }
    array->length--;
}
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// assuming you have unique array numbers
void linear_search(Array_t *array, int input) {
    int i = 0;
    while (i < array->length) {
        if(array->A[i] == input) {
            printf("\nInput %d is found at index %d\n", input, i);
            //this is for linear search improvement efforts in case you have 
            //another inquiry for the same input
            swap(&array->A[i], &array->A[0]);
            return;
        }
        i++;
    }
    printf("\nERROR: Input %d is NOT found\n", input);
}
// assuming that the array is already sorted and contains unique array numbers
void binary_search(Array_t *array, int input) {
    if (array->length < 1) {
        printf("\nERROR: array length is less than one\n");
        return;
    }
    int low = 0, high = array->length - 1, mid = (low + high) / 2;
    while(low <= high) {
        if (array->A[mid] == input) {
            printf("\nInput %d is found at index %d\n", input, mid);
            return;
        }
        else if (array->A[mid] < input) {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else {
            high = mid - 1;
            mid = (low + high) / 2;
        } 
    }

    printf("\nERROR: Input %d is NOT found\n", input);
    return;
}
// assuming that the array is already sorted and contains unique array numbers
void binary_search_recursive(Array_t *array, int input, int low, int high) {
    if (array->length < 1) {
        printf("\nERROR: array length is less than one\n");
        return;
    }

    if (low <= high) {
        int mid = (low + high) / 2;
        if (array->A[mid] == input) {
            printf("\nInput %d is found at index %d\n", input, mid);
            return;
        }
        else if (array->A[mid] < input) {
            low = mid + 1;
            binary_search_recursive(array,input,low,high);
            return;
        }
        else {
            high = mid - 1;
            binary_search_recursive(array,input,low,high);
            return;
        } 
    }
    printf("\nERROR: Input %d is NOT found\n", input);
    return;
}

// you may as well pass in the array by value as we are not modifying the array
int get(Array_t *array, int index) {
    if(index >= 0 && index < array->length) {
        return array->A[index];
    }

    return -1;
}

void set(Array_t *array, int index, int input) {
    if(index >= 0 && index < array->length) {
        array->A[index] = input;
    }
}

int max(Array_t *array) {
    if(array->length > 0) {
        int max = array->A[0];
        int i = 1;
        while (i < array->length) {
            if(array->A[i] > max) {
                max = array->A[i];
            }
            i++;
        }
        return max;
    }
    return -1;
}

int min(Array_t *array) {
    if(array->length > 0) {
        int min = array->A[0];
        int i = 1;
        while (i < array->length) {
            if(array->A[i] < min) {
                min = array->A[i];
            }
            i++;
        }
        return min;
    }
    return -1;
}

int sum(Array_t *array) {
    int sum = 0;
    for(int i = 0; i < array->length; i++) {
        sum += array->A[i];
    }
    return sum;
}

float average(Array_t *array) {
    return (float)sum(array) / array->length;
}

void reverse(Array_t *array) {
    int i = 0, j = array->length - 1;
    while(i < j) {
        swap(&array->A[i], &array->A[j]);
        i++, j--;
    }
}

void right_shift(Array_t *array) {
    array->length--;
}

void left_shift(Array_t *array) {
    int i = 0;
    while(i < array->length - 1) {
        array->A[i] = array->A[i+1];
        i++;
    }
    array->length--;
}

// insert an element in a sorted array
void insert_sorted(Array_t *array, int input) {
    if(array->length == array->size) {
        printf("\nERROR: No enough space to insert element %d\n", input);
        return;
    }
    int i = array->length - 1;
    while(i >= 0 && array->A[i] > input) {
        array->A[i+1] = array->A[i];
        i--;
    }
    array->A[i+1] = input;
    array->length++;
}

bool is_sorted(Array_t *array) {
    int i = 0;
    while (i < array->length - 1) {
        if(array->A[i] > array->A[i+1]) {
            return false;
        }
        i++;
    }
    return true;
}

// move negative element to left and positive to right
void rearrange(Array_t *array) {
    int i = 0, j = array->length - 1;
    while (i < j)
    {
        while (array->A[i] < 0) { i++; }
        while (array->A[j] >= 0) { j--; }

        if (i < j) {
            swap(&array->A[i], &array->A[j]);
        }
    } 
}

// merge 2 sorted arrays into one array
Array_t * merge(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    while (array1->A[i] && array2->A[j]) {
        if (array1->A[i] < array2->A[j]) {
            array3->A[k++] = array1->A[i++]; 
        } else {
            array3->A[k++] = array2->A[j++];
        }
    }
    while (array1->A[i]) {
        array3->A[k++] = array1->A[i++];
    }
    while (array2->A[j]) {
        array3->A[k++] = array2->A[j++];
    }
    array3->length = array1->length + array2->length;
    array3->size = 10;
    return array3;
}
int main() {
    Array_t array1 = {{1,5,6,9,99}, 10, 5};
    display(&array1);
    insert(&array1,10,1);
    display(&array1);
    linear_search(&array1,1);
    binary_search(&array1,102);
    display(&array1);
    binary_search(&array1,5);
    binary_search_recursive(&array1,10,0,array1.length - 1);
    delete(&array1,1);
    display(&array1);
    set(&array1, 1, 50);
    display(&array1);
    printf("\nMax value is %d\n", max(&array1));
    printf("\nMin value is %d\n", min(&array1));
    printf("\nAverage value is %f\n", average(&array1));
    reverse(&array1);
    display(&array1);
    right_shift(&array1);
    display(&array1);
    left_shift(&array1);
    display(&array1);

    Array_t array2 = {{1,4,6,7,9}, 10, 5};
    Array_t array3 = {{2,3,4,5,10}, 10, 5};
    Array_t *merged_array;
    display(&array2);
    display(&array3);
    merged_array = merge(&array2,&array3);
    display(merged_array);

    return 0;
}