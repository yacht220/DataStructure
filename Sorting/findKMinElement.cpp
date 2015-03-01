/*
 * Find K minmum element in given array.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insertionSort.h"
#include "heapSort.h"

void findKMinElement(int array[], int size, int numOfMin)
{
    //insertionSort(array, size);

    buildHeapFromGivenArray(array, size);
    heapSort(array, size);

    for(int i = 0; i < numOfMin; i++)
    {
        printf("%d, ", array[i]);
    }
}

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int size = sizeof(array)/sizeof(array[0]);
    findKMinElement(array, size, 5);
}
