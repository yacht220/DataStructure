/*
 * Find K minmum elements in given array.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insertionSort.h"
#include "heapSort.h"

/*void findKMinElements(int array[], int size, int numOfMin)
  {
//insertionSort(array, size);

buildHeapFromGivenArray(array, size);
heapSort(array, size);

for(int i = 0; i < numOfMin; i++)
{
printf("%d, ", array[i]);
}
}*/

/**
 * @brief Do as insertion sort but only maintain the first K elements (sub-array) in array 
 */
void findKMinElementsVariantA(int array[], int size, int numOfMin)
{
    insertionSort(array, numOfMin);

    int iteratorIndexOutOfSubArray = numOfMin;
    int lastIndexInSubArray = numOfMin - 1;
    int interatorIndexInSubArray = lastIndexInSubArray - 1;
    int curElem = 0;

    while (iteratorIndexOutOfSubArray < size)
    {
        if (array[iteratorIndexOutOfSubArray] < array[lastIndexInSubArray])
        {
            curElem = array[iteratorIndexOutOfSubArray];
            array[iteratorIndexOutOfSubArray] = array[lastIndexInSubArray];
            for (interatorIndexInSubArray = lastIndexInSubArray - 1; 
                    interatorIndexInSubArray >= 0 && array[interatorIndexInSubArray] > curElem; 
                    interatorIndexInSubArray--)
            {
                array[interatorIndexInSubArray + 1] = array[interatorIndexInSubArray];
            }

            array[interatorIndexInSubArray + 1] = curElem;
        }

        iteratorIndexOutOfSubArray++;
    }

    for (int i = 0; i < numOfMin; i++)
    {
        printf("%d, ", array[i]);
    }
}

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int size = sizeof(array)/sizeof(array[0]);
    //findKMinElements(array, size, 5);
    findKMinElementsVariantA(array, size, 10);
}
