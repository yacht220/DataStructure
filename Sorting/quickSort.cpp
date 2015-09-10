/*
 * Quicksort.
 */

#include <stdio.h>
#include <stdio.h>
#include "quickSortUtility.h"

int main(int argc, char** argv)
{
    //int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int array[] = {40, 2000, 78, 1100, 23, 45}; // Bug will appear for this array. Pls see details in quickSortUtility.cpp. 
    int size = sizeof(array) / sizeof(array[0]);
    printf("Before sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\nAfter sorting: ");
    quickSort(array, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    
    return 1;
}
