/*
 * Quicksort.
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
    for(int index = firstLargerIndex; index <= right; index++)
    {
        if(array[index] < pivot)
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

void quickSort(int array[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int pivotIndex = partition(array, left, right);
    quickSort(array, left, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, right);
}

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29}; 
    int size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    quickSort(array, 0, size - 1);
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}
