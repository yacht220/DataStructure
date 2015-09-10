/*
 * Find Kth minimum element in given array.
 */

#include <stdlib.h>
#include <stdio.h>
#include "insertionSort.h"
#include "quickSortUtility.h"

/**
 * @brief Do as quicksort.
 * @param kthMin - Begin with 1.
 */
void quickSelect(int array[], int left, int right, int kthMin)
{
    int size = right - left + 1;
    if (size > 3)
    {
        int pivotIndex = median(array, left, right);
        int pivot = array[pivotIndex];

        array[pivotIndex] = array[right - 1];
        array[right - 1] = pivot;

        int i = left;
        int j = right - 1;
        int tmp = 0;
        for (;;)
        {
            while (array[++i] < pivot) {}
            // BUG!! j could be 0!!
            while (array[--j] > pivot) {}
            if (i < j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            else
            {
                break;
            }
        }

        array[right - 1] = array[i];
        array[i] = pivot;

        if (kthMin - 1 < i)
        {
            quickSelect(array, left, i - 1, kthMin);
        }
        else if (kthMin - 1 > i)
        {
            quickSelect(array, i + 1, right, kthMin);
        }
        else
        {
            printf("%dth minimum element is pivot itself.\n", kthMin);
        }
    }
    else
    {
        printf("Do insertion sort.\n");
        insertionSort(array, size);
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage.\n");
        return -1;
    }

    int kthMin = atoi(argv[1]);
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int left = 0;
    int right = (sizeof(array) / sizeof(array[0])) - 1;
    quickSelect(array, left, right, kthMin);
    printf("%dth minimum element in array is %d.\n", kthMin, array[kthMin - 1]);
}
