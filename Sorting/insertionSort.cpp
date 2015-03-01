#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertionSort(int array[], int size)
{
    int firstUnsortedIndex = 0;
    int sortedIndex = 0;
    int curUnsortedElement = 0;
    for(firstUnsortedIndex = 1; firstUnsortedIndex < size; firstUnsortedIndex++)
    {
        curUnsortedElement = array[firstUnsortedIndex];
        sortedIndex = firstUnsortedIndex - 1;
        while(curUnsortedElement < array[sortedIndex] && sortedIndex >= 0)
        {
            array[sortedIndex+1] = array[sortedIndex];
            sortedIndex--;
        }
        array[sortedIndex+1] = curUnsortedElement;
    }
}
