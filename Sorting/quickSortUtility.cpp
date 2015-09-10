/*
 * Quicksort utility.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(int array[], int left, int right)
{
    int pivot = array[left];
    int firstLargerIndex = left+1;
    int pivotIndex = 0;
    int tmpValue = 0;
    for (int index = firstLargerIndex; index <= right; index++)
    {
        if (array[index] < pivot)
        {
            tmpValue = array[index];
            array[index] = array[firstLargerIndex];
            array[firstLargerIndex] = tmpValue;
            firstLargerIndex++;
        }
    }

    pivotIndex = firstLargerIndex-1;
    tmpValue = array[pivotIndex];
    array[pivotIndex] = array[left];
    array[left] = tmpValue;

    return pivotIndex;
}

int median(int array[], int left, int right)
{
    int tmp = 0;
    int mid = (left + right) / 2;

    printf("median - left = %d, right = %d, mid = %d\n", left, right, mid);

    if (array[left] > array[mid])
    {
        tmp = array[left];
        array[left] = array[mid];
        array[mid] = tmp;
    }

    if (array[right] < array[mid])
    {
        if (array[right] < array[left])
        {
            tmp = array[right];
            array[right] = array[mid];
            array[mid] = array[left];
            array[left] = tmp;
        }
        else
        {
            tmp = array[right];
            array[right] = array[mid];
            array[mid] = tmp;
        }
    }

    return mid;
}

int partitionOptimized(int array[], int left, int right)
{
    printf("\nleft = %d, right = %d\n", left, right);
    /* Find pivot */
    int pivotIndex = median(array, left, right);
    printf("pivotIndexTmp = %d\n", pivotIndex);

    /* Swap pivot with value in right - 1 */
    int pivot = array[pivotIndex];
    array[pivotIndex] = array[right - 1];
    array[right - 1] = pivot;

    /* Put smaller in left and larger in right */
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

    /* Restore pivot to location i */
    array[right - 1] = array[i];
    array[i] = pivot;

    return i;
}

void quickSort(int array[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    //int pivotIndex = partition(array, left, right);
    int pivotIndex = partitionOptimized(array, left, right);
    printf("pivotIndex = %d\n", pivotIndex);
    quickSort(array, left, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, right);
}
