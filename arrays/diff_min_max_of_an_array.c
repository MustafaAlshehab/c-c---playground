#include <stdio.h>

int diff_min_and_max_val(int *arr, int size)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("minmum val %d\n", min);
    printf("maximum val %d\n", max);

    return max - min;
}

int main()
{
    int array[] = {1, 2, 90, 10, 110};
    int size_of_array = sizeof(array) / sizeof(array[0]);
    int result = diff_min_and_max_val(array, size_of_array);
    printf("diff %d\n", result);
    return 0;
}