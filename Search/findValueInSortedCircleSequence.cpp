/*
 * Find a given value in sorted circle sequence with O(logN) time complexity.
 * TIP: Try some algorithm with binary search idea.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findValueInSortedCircleSequence(int value, int array[], int begin, int end)
{
    int mid = (begin + end) / 2;

    printf("begin = %d, mid = %d, end = %d.\n", begin, mid, end);
    
    if (value == array[mid])
    {
        return mid;
    }
    else if (begin >= end)
    {
        return -1;
    }
    else if (value < array[mid])
    {
        if (value == array[begin])
        {
            return begin;
        }
        else if (array[begin] < array[mid])
        {
            if (value > array[begin])
            {
                return findValueInSortedCircleSequence(value, array, begin + 1, mid - 1);
            }
            else
            {
                return findValueInSortedCircleSequence(value, array, mid + 1, end);
            }

        }
        else
        {
            return findValueInSortedCircleSequence(value, array, begin + 1, mid - 1);
        }
    }
    else
    {
        if (value == array[end])
        {
            return end;
        }
        else if (array[mid] < array[end])
        {
            if (value < array[end])
            {
                return findValueInSortedCircleSequence(value, array, mid + 1, end - 1);
            }
            else
            {
                return findValueInSortedCircleSequence(value, array, begin, mid - 1);
            }
        }
        else
        {
            return findValueInSortedCircleSequence(value, array, mid + 1, end - 1);
        }
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage!\n");
        return -1;
    }

    int targetValue = atoi(argv[1]);
    int array[] = {9, 11, 12, 13, 14, 15, 16, 6, 7, 8};
    int retIndex = findValueInSortedCircleSequence(targetValue, array, 0, (sizeof(array) / sizeof(array[0]) - 1));

    if (-1 == retIndex)
    {
        printf("Not found.\n");
    }
    else
    {
        printf("Found index %d, value %d.\n", retIndex, array[retIndex]);
    }

    return 1;
}
