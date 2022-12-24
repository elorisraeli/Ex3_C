#include <stdio.h>

#define NUM_OF_INPUTS 50

void shift_element(int *arr, int i)
{
    int counter = i;
    int *index;
    while (counter != 0)
    {
        index = (arr + counter);
        *(index) = *(index - 1);
        counter -= 1;
    }
}

void insertion_sort(int *arr, int len)
{
    int key, i;
    for (int j = 1; j < len; j++)
    {
        key = *(arr + j);
        i = j - 1;
        while ((i >= 0) && (key < *(arr + i)))
        {
            *(arr + (i + 1)) = *(arr + i);
            i -= 1;
        }
        *(arr + (i + 1)) = key;
    }
}

int main()
{
    // insertion sort
    int arr[NUM_OF_INPUTS];
    for (int i = 0; i < NUM_OF_INPUTS; i++)
    {
        scanf("%d", (arr + i));
    }

    printf("\n\nThe Array is: \n");
    for (int i = 0; i < NUM_OF_INPUTS; i++)
    {
        printf("%d,", *(arr + i));
    }
    printf("\nSorting...\n");
    insertion_sort(arr, NUM_OF_INPUTS);
    printf("\nAfter Sort: \n");
    for (int i = 0; i < NUM_OF_INPUTS; i++)
    {
        printf("%d,", *(arr + i));
    }
    return 0;
}