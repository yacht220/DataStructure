/*
 * Binary search for a given sorted array.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(int sortedArray[], int left, int right, int targetData)
{
    int pivotIndex = (right + left) / 2;

    if(sortedArray[pivotIndex] == targetData)
    {
        return pivotIndex;
    }
    else if(left >= right)
    {
        printf("Nothing found.\n");
        return -1;
    }
    else if(sortedArray[pivotIndex] > targetData)
    {
        return binarySearch(sortedArray, left, pivotIndex - 1, targetData);
    }
    else
    {
        return binarySearch(sortedArray, pivotIndex + 1, right, targetData);
    }
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Wrong usage.\n");
	return -1;
    }

    int targetData = atoi(argv[1]);
    int sortedArray[] = {3, 9, 10, 35, 79, 200, 230, 240, 500};
    int left = 0;
    int right = sizeof(sortedArray)/sizeof(sortedArray[0]) - 1; 
    int foundIndex = -1;
    if(-1 == (foundIndex = binarySearch(sortedArray, left, right, targetData)))
    {
        return -1;
    }
    else
    {
        printf("Target data: %d. Found index: %d. Value in array: %d.\n", 
               targetData, 
	       foundIndex,
	       sortedArray[foundIndex]);
    }
}
