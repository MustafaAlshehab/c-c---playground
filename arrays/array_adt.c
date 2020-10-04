#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Array {
    int *A;
    int size;
    int length;
}Array_t;

void display(Array_t *array) {
    if(array->length < 1) {
        printf("\nNo elements to display\n");
        return;
    }
    printf("\nArray elements: ");
    for(int i = 0; i < array->length; i++) {
        printf("%d ", array->A[i]);
    }
    printf("\n");
}

void insert(Array_t *array, int input, int index) {
    if (index < 0 || index > array->length) {
        printf("\nERROR: inserting index %d index cannot be negative or greater than length\n", index);
        return;
    }
    int i = array->length;
    for (; i > index; i--)
    {
        array->A[i] = array->A[i-1];
    }
    array->A[i] = input;
    array->length++;
}

void append(Array_t *array, int input) {
    if (array->length >= array->size) {
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

    for (int i = index; i < array->length - 1; i++)
    {
        array->A[i] = array->A[i+1];
    }
    array->length--;
}

// helper function
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// assuming you have unique array numbers
void linear_search(Array_t *array, int input) {
    for (int i = 0; i < array->length; i++) {
        if(array->A[i] == input) {
            printf("\nInput %d is found at index %d\n", input, i);
            //this is for linear search improvement efforts in case you have 
            //another inquiry for the same input
            swap(&array->A[i], &array->A[0]);
            return;
        }
    }
    printf("\nERROR: Input %d is NOT found\n", input);
}

// assuming that the array is already sorted and contains unique array elements
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

// assuming that the array is already sorted and contains unique array elements
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

// check if a given array of elements is sorted 
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
Array_t * merge_sorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    while (i < array1->length && j < array2->length) {
        if (array1->A[i] < array2->A[j]) {
            array3->A[k++] = array1->A[i++]; 
        } else {
            array3->A[k++] = array2->A[j++];
        }
    }
    while (i < array1->length) {
        array3->A[k++] = array1->A[i++];
    }
    while (j < array2->length) {
        array3->A[k++] = array2->A[j++];
    }

    array3->length = array1->length + array2->length;
    array3->size = 10;

    return array3;
}

// combine 2 unsorted arrays into one without duplicate
// Tine complexity O(N^2)
Array_t * union_unsorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    array3->length = 0;
    while(i < array1->length) {
        array3->A[k++] = array1->A[i++];
        array3->length++;
    }
    for( ;j < array2->length; j++) {
       bool value_exist = false;
       for (int c = 0; c < array3->length; c++) {
           if(array2->A[j] == array3->A[c]) {
               value_exist = true;
               break;
           }
       }
       if (value_exist == false) {
           array3->A[k++] = array2->A[j];
           array3->length++;
       }
    }

    array3->size = 10;

    return array3;
}

// combine 2 sorted arrays into one without duplicate
// Tine complexity O(N)
Array_t * union_sorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    while ( i < array1->length && j < array2->length ) {
        if (array1->A[i] < array2->A[j]) {
            array3->A[k++] = array1->A[i++];
        } else if (array1->A[i] == array2->A[j]) {
            array3->A[k++] = array1->A[i++];
            j++;
        } else {
            array3->A[k++] = array2->A[j++];
        }
    }
    while ( i < array1->length ) {
        array3->A[k++] = array1->A[i++];
    }
    
    while ( j < array2->length ) {
        array3->A[k++] = array2->A[j++];
    }

    array3->length = k;
    array3->size = 10;

    return array3;
}

// store only common elements from first and second 
// array into a new array
// Tine complexity O(N^2)
Array_t * intersection_unsorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    for( ; i < array1->length; i++ ) {
        for ( ; j < array2->length; j++ ) {
            if ( array1->A[i] == array2->A[j] ) {
                array3->A[k++] = array1->A[i];
                break;
            }
        }
    }
    array3->length = k;
    array3->size = 10;

    return array3;
}

// store only common elements from first and second 
// array into a new array
// Tine complexity O(N)
Array_t * intersection_sorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    while ( i < array1->length && j < array2->length ) {
        if (array1->A[i] < array2->A[j]) {
            i++;
        } else if (array1->A[i] == array2->A[j]) {
            array3->A[k++] = array1->A[i++];
            j++;
        } else {
            j++;
        }
    }

    array3->length = k;
    array3->size = 10;

    return array3;
}

// store elements in first array that are
// not in second array into a new array
// Tine complexity O(N^2)
Array_t * difference_unsorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    for( ; i < array1->length; i++ ) {
        bool element_match = false;
        for ( ; j < array2->length; j++ ) {
            if ( array1->A[i] == array2->A[j] ) {
                element_match = true;
                break;
            }
        }
        if (element_match == false)
        {
            array3->A[k++] = array1->A[i];
        }
    }

    array3->length = k;
    array3->size = 10;

    return array3;
}

// store elements in first array that are
// not in second array into a new array
// Tine complexity O(N)
Array_t * difference_sorted(Array_t *array1, Array_t *array2) {
    int i = 0, j = 0, k = 0;
    Array_t *array3 = (Array_t *)malloc(sizeof(Array_t));
    while ( i < array1->length && j < array2->length ) {
        if (array1->A[i] == array2->A[j]) {
            i++;
            j++;
        } else if (array1->A[i] < array2->A[j]) {
            array3->A[k++] = array1->A[i++];
        } else {
            j++;
        }
    }
    
    while (i < array1->length) {
        array3->A[k++] = array1->A[i++];
    }
    
    array3->length = k;
    array3->size = 10;

    return array3;
}

void program_menu() {
    Array_t array1;
    int choice, input, index;

    printf("\nEnter a size of an array: ");;
    while (scanf("%d", &array1.size) == 0) {
        printf("\nPlease Enter a valid input\n");
        int c;
        while((c=getchar())!='\n' && c!=EOF);
    }
    array1.A = (int *)malloc(array1.size * sizeof(int));
    array1.length = 0;

    do {
        printf("\n\nMain Menu\n");
        printf("1. Insert\n");
        printf("2. Append\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Sum\n");
        printf("6. Display\n");
        printf("7. Exit\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an element followed by an index: ");
            scanf("%d%d", &input, &index);
            insert(&array1,input,index);
            break;
        case 2: 
            printf("Enter an index to append: ");
            scanf("%d", &input);
            append(&array1, input);    
            break;
        case 3: 
            printf("Enter an index to delete: ");
            scanf("%d", &index);
            delete(&array1, index);    
            break;
        case 4:
            printf("Enter an element to search for: ");
            scanf("%d", &input);
            linear_search(&array1, input);
            break;
        case 5:
            printf("The sum of the elements is: %d\n", sum(&array1));
            break;
        case 6:
            display(&array1);       
        }
    } while(choice < 7);

}

int main() {
    
    program_menu();

    return 0;
}