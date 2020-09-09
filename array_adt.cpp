#include <iostream>

class Array {
private:    
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array() {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int size) {
        this->size = size;
        length = 0;
        A = new int[size];
    }
    ~Array() {
        delete []A;
    }
    void display();
    void insert(int input, int index);
    void append(int input);
    void delete_element(int index);
    void linear_search(int input);
    void binary_search(int input);
    void binary_search_recursive(int input, int low, int high);
    int get(int index);
    void set(int index, int input);
    int max();
    int min();
    int sum();
    float average();
    void reverse();
    void right_shift();
    void left_shift();
    void insert_sorted(int input);
    bool is_sorted();
    void rearrange();
    Array * merge_sorted(Array &array2);
    Array * union_unsorted(Array &array2);
    Array * union_sorted(Array &array2);
    Array * intersection_unsorted(Array &array2);
    Array * intersection_sorted(Array &array2);
    Array * difference_unsorted(Array &array2);
    Array * difference_sorted(Array &array2);

};

// helper function
void Array::swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Array::display() {
    if(length < 1) {
        printf("\nNo elements to display\n");
        return;
    }
    printf("\nArray elements: ");
    for(int i = 0; i < length; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Array::insert(int input, int index) {
    if (index < 0 || index > length) {
        printf("\nERROR: inserting index %d index cannot be negative or greater than length\n", index);
        return;
    }
    int i = length;
    for (; i > index; i--)
    {
        A[i] = A[i-1];
    }
    A[i] = input;
    length++;
}

void Array::append(int input) {
    if (length >= size) {
        printf("\nERROR: there is no more avaliable space to store %d in the array\n", input);
        return;
    }
    A[length] = input;
    length++;
}

void Array::delete_element(int index) {
    if (index < 0 || index > length) {
        printf("\nERROR: Deleting index %d - index cannot be negative or greater than length\n", index);
        return;
    }

    for (int i = index; i < length - 1; i++)
    {
        A[i] = A[i+1];
    }
    length--;
}

// assuming you have unique array numbers
void Array::linear_search(int input) {
    for (int i = 0; i < length; i++) {
        if(A[i] == input) {
            printf("\nInput %d is found at index %d\n", input, i);
            //this is for linear search improvement efforts in case you have 
            //another inquiry for the same input
            swap(&A[i], &A[0]);
            return;
        }
    }
    printf("\nERROR: Input %d is NOT found\n", input);
}

// assuming that the array is already sorted and contains unique array elements
void Array::binary_search(int input) {
    if (length < 1) {
        printf("\nERROR: array length is less than one\n");
        return;
    }
    int low = 0, high = length - 1, mid = (low + high) / 2;
    while(low <= high) {
        if (A[mid] == input) {
            printf("\nInput %d is found at index %d\n", input, mid);
            return;
        }
        else if (A[mid] < input) {
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
void Array::binary_search_recursive(int input, int low, int high) {
    if (length < 1) {
        printf("\nERROR: array length is less than one\n");
        return;
    }

    if (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == input) {
            printf("\nInput %d is found at index %d\n", input, mid);
            return;
        }
        else if (A[mid] < input) {
            low = mid + 1;
            binary_search_recursive(input,low,high);
            return;
        }
        else {
            high = mid - 1;
            binary_search_recursive(input,low,high);
            return;
        } 
    }
    printf("\nERROR: Input %d is NOT found\n", input);
    return;
}

// you may as well pass in the array by value as we are not modifying the array
int Array::get(int index) {
    if(index >= 0 && index < length) {
        return A[index];
    }

    return -1;
}

void Array::set(int index, int input) {
    if(index >= 0 && index < length) {
        A[index] = input;
    }
}

int Array::max() {
    if(length > 0) {
        int max = A[0];
        for (int i = 1; i < length; i++) {
            if(A[i] > max) {
                max = A[i];
            }
        }
        return max;
    }
    return -1;
}

int Array::min() {
    if(length > 0) {
        int min = A[0];
        for (int i = 1; i < length; i++) {
            if(A[i] < min) {
                min = A[i];
            }
        }
        return min;
    }
    return -1;
}

int Array::sum() {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += A[i];
    }
    return sum;
}

float Array::average() {
    return (float)sum() / length;
}

void Array::reverse() {
    int i = 0, j = length - 1;
    while(i < j) {
        swap(&A[i], &A[j]);
        i++, j--;
    }
}

void Array::right_shift() {
    length--;
}

void Array::left_shift() {
    int i = 0;
    while(i < length - 1) {
        A[i] = A[i+1];
        i++;
    }
    length--;
}

// insert an element in a sorted array
void Array::insert_sorted(int input) {
    if(length == size) {
        printf("\nERROR: No enough space to insert element %d\n", input);
        return;
    }
    int i = length - 1;
    while(i >= 0 && A[i] > input) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = input;
    length++;
}

// check if a given array of elements is sorted 
bool Array::is_sorted() {
    int i = 0;
    while (i < length - 1) {
        if(A[i] > A[i+1]) {
            return false;
        }
        i++;
    }
    return true;
}

// move negative element to left and positive to right
void Array::rearrange() {
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (A[i] < 0) { i++; }
        while (A[j] >= 0) { j--; }

        if (i < j) {
            swap(&A[i], &A[j]);
        }
    } 
}

// merge 2 sorted arrays into one array
Array * Array::merge_sorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    while (i < length && j < array2.length) {
        if (A[i] < array2.A[j]) {
            array3->A[k++] = A[i++]; 
        } else {
            array3->A[k++] = array2.A[j++];
        }
    }
    while (i < length) {
        array3->A[k++] = A[i++];
    }
    while (j < array2.length) {
        array3->A[k++] = array2.A[j++];
    }

    array3->length = length + array2.length;
    array3->size = 10;

    return array3;
}

// combine 2 unsorted arrays into one without duplicate
// Tine complexity O(N^2)
Array * Array::union_unsorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    while(i < length) {
        array3->A[k++] = A[i++];
        array3->length++;
    }
    for( ;j < array2.length; j++) {
       bool value_exist = false;
       for (int c = 0; c < array3->length; c++) {
           if(array2.A[j] == array3->A[c]) {
               value_exist = true;
               break;
           }
       }
       if (value_exist == false) {
           array3->A[k++] = array2.A[j];
           array3->length++;
       }
    }

    array3->size = 10;

    return array3;
}

// combine 2 sorted arrays into one without duplicate
// Tine complexity O(N)
Array * Array::union_sorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    while ( i < length && j < array2.length ) {
        if (A[i] < array2.A[j]) {
            array3->A[k++] = A[i++];
        } else if (A[i] == array2.A[j]) {
            array3->A[k++] = A[i++];
            j++;
        } else {
            array3->A[k++] = array2.A[j++];
        }
    }
    while ( i < length ) {
        array3->A[k++] = A[i++];
    }
    
    while ( j < array2.length ) {
        array3->A[k++] = array2.A[j++];
    }

    array3->length = k;
    array3->size = 10;

    return array3;
}

// store only common elements from first and second 
// array into a new array
// Tine complexity O(N^2)
Array * Array::intersection_unsorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    for( ; i < length; i++ ) {
        for ( ; j < array2.length; j++ ) {
            if ( A[i] == array2.A[j] ) {
                array3->A[k++] = A[i];
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
Array * Array::intersection_sorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    while ( i < length && j < array2.length ) {
        if (A[i] < array2.A[j]) {
            i++;
        } else if (A[i] == array2.A[j]) {
            array3->A[k++] = A[i++];
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
Array * Array::difference_unsorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    for( ; i < length; i++ ) {
        bool element_match = false;
        for ( ; j < array2.length; j++ ) {
            if ( A[i] == array2.A[j] ) {
                element_match = true;
                break;
            }
        }
        if (element_match == false)
        {
            array3->A[k++] = A[i];
        }
    }

    array3->length = k;
    array3->size = 10;

    return array3;
}

// store elements in first array that are
// not in second array into a new array
// Tine complexity O(N)
Array * Array::difference_sorted(Array &array2) {
    int i = 0, j = 0, k = 0;
    Array *array3 = new Array(length + array2.length);
    while ( i < length && j < array2.length ) {
        if (A[i] == array2.A[j]) {
            i++;
            j++;
        } else if (A[i] < array2.A[j]) {
            array3->A[k++] = A[i++];
        } else {
            j++;
        }
    }
    
    while (i < length) {
        array3->A[k++] = A[i++];
    }
    
    array3->length = k;
    array3->size = 10;

    return array3;
}

void program_menu() {
    Array *array1;
    int choice, input, index, size;

    printf("\nEnter a size of an array: ");;
    while (scanf("%d", &size) == 0) {
        printf("\nPlease Enter a valid input\n");
        int c;
        while((c=getchar())!='\n' && c!=EOF);
    }
    array1 = new Array(size);

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
            array1->insert(input,index);
            break;
        case 2: 
            printf("Enter an index to append: ");
            scanf("%d", &input);
            array1->append(input);    
            break;
        case 3: 
            printf("Enter an index to delete: ");
            scanf("%d", &index);
            array1->delete_element(index);    
            break;
        case 4:
            printf("Enter an element to search for: ");
            scanf("%d", &input);
            array1->linear_search(input);
            break;
        case 5:
            printf("The sum of the elements is: %d\n", array1->sum());
            break;
        case 6:
            array1->display();       
        }
    } while(choice < 7);

}

int main() {
    
    program_menu();

    return 0;
}