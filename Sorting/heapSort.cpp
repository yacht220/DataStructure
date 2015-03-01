#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void siftHeapDownFromCurParent(int array[], int curParentIndex, int size)
{
    int leftChildIndex = curParentIndex * 2 + 1;
    int rightChildIndex = leftChildIndex + 1;
    int largestChildIndex = leftChildIndex;
    while(leftChildIndex < size)
    {
        if(rightChildIndex < size && array[leftChildIndex] < array[rightChildIndex])
	{
	    largestChildIndex = rightChildIndex;
	}

	if(array[largestChildIndex] < array[curParentIndex])
	{
	    break;
	}

	int tmp = array[curParentIndex];
	array[curParentIndex] = array[largestChildIndex];
	array[largestChildIndex] = tmp;

	curParentIndex = largestChildIndex;
	leftChildIndex = curParentIndex * 2 + 1;
	rightChildIndex = leftChildIndex + 1;
	largestChildIndex = leftChildIndex;
    }

}

void buildHeapFromGivenArray(int array[], int size)
{
    int lastParentIndexInArray = (size - 2) / 2;
    for(int curParentIndex = lastParentIndexInArray; curParentIndex >= 0; curParentIndex--)
    {
        siftHeapDownFromCurParent(array, curParentIndex, size);
    }
}

void heapSort(int array[], int size)
{
    for(int unsortedSize = size; unsortedSize > 0; unsortedSize--)
    {
        int tmp = array[0];
        array[0] = array[unsortedSize - 1];
	array[unsortedSize - 1] = tmp;
        siftHeapDownFromCurParent(array, 0, unsortedSize - 1);
    }
}
