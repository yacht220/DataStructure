#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int* mergeSort(int array[], int size)
{
    if(1 == size)
    {
        return array;
    }

    int firstHalfSize = (int)(size/2);
    int secondHalfSize = size - firstHalfSize;
    int startIndexOfSecondHalf = firstHalfSize;

    int* firstSortedArray = mergeSort(&array[0], firstHalfSize);
    int* secondSortedArray = mergeSort(&array[startIndexOfSecondHalf], secondHalfSize);
    int* resultSortedArray = (int*)malloc(size * sizeof(int));
     
    int firstSortedArrayIndex = 0;
    int secondSortedArrayIndex = 0;
    int resultSortedArrayIndex = 0;

    while(firstSortedArrayIndex < firstHalfSize && secondSortedArrayIndex < secondHalfSize)
    {
        if(firstSortedArray[firstSortedArrayIndex] < secondSortedArray[secondSortedArrayIndex])
	{
            resultSortedArray[resultSortedArrayIndex] = firstSortedArray[firstSortedArrayIndex];
            firstSortedArrayIndex++;
        }
        else
        {
	    resultSortedArray[resultSortedArrayIndex] = secondSortedArray[secondSortedArrayIndex];
	    secondSortedArrayIndex++;
	}
        resultSortedArrayIndex++;
    }

    if(firstSortedArrayIndex >= firstHalfSize)
    {
        memcpy(&resultSortedArray[resultSortedArrayIndex], 
	        &secondSortedArray[secondSortedArrayIndex],
	        (size - resultSortedArrayIndex) * sizeof(int));
   
        /*for(int i = resultSortedArrayIndex; i < size; i++)
	{
	    resultSortedArray[i] = secondSortedArray[secondSortedArrayIndex];
            secondSortedArrayIndex++;
	}*/
    }
    else
    {
        for(int i = resultSortedArrayIndex; i < size; i++)
        {
            resultSortedArray[i] = firstSortedArray[firstSortedArrayIndex];
            firstSortedArrayIndex++;
        }
    }

    //free(firstSortedArray);
    //free(secondSortedArray);
    return resultSortedArray;
}

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    int size = sizeof(array)/sizeof(array[0]);
    int* resultArray = mergeSort(array, size);
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", resultArray[i]);
    }
    printf("\n");
}
