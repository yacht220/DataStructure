/*
 * Find max sum of subsequence in a given sequence.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxSubsequenceSum(int array[], int size)
{
    int maxSum = 0;
    int tmpSum = 0;
    int* maxSumSubsequence = (int*)malloc(size * sizeof(int));
    int maxSumSubsequenceStartAnchorIndex = 0;
    int maxSumSubsequenceSize = 0;

    for (int i = 0; i < size; i++)
    {
        tmpSum += array[i];

        if (tmpSum < 0)
        {
            maxSumSubsequenceStartAnchorIndex = i + 1;
            tmpSum = 0;
        }
        else if (tmpSum > maxSum)
        {
            maxSumSubsequenceSize = 0;
            for (int j = maxSumSubsequenceStartAnchorIndex, k = 0; j <= i; j++, k++ )
            {
                maxSumSubsequence[k] = array[j];
                maxSumSubsequenceSize++;
            }
            maxSum = tmpSum;
        }
    }

    printf("%s() Subsequence with max sum: ", __func__);
    for (int i = 0; i < maxSumSubsequenceSize; i++)
    {
        printf("%d ", maxSumSubsequence[i]);
    }
    printf("\n");

    return maxSum;
}

int maxSubSequenceSumWithoutExtraBuffer(int array[], int size)
{
    int maxSum = 0;
    int tmpSum = 0;
    int maxSumSubSequenceStartIndexTmp = 0;
    int maxSumSubSequenceStartIndex = 0;
    int maxSumSubSequenceEndIndex = 0;

    for (int i = 0; i < size; i++)
    {
        tmpSum += array[i];

        if (tmpSum < 0)
        {
            maxSumSubSequenceStartIndexTmp = i + 1;
            tmpSum = 0;
        }
        else if (tmpSum > maxSum)
        {
            if (maxSumSubSequenceStartIndex != maxSumSubSequenceStartIndexTmp)
            {
                maxSumSubSequenceStartIndex = maxSumSubSequenceStartIndexTmp;
            }
            maxSumSubSequenceEndIndex = i;
            maxSum = tmpSum;
        }
    }

    printf("%s() Subsequence with max sum: ", __func__);
    for (int i = maxSumSubSequenceStartIndex; i<= maxSumSubSequenceEndIndex; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return maxSum;
}

int main(int argc, char** argv)
{
    int dataSet[] = {-40, 2, -78, 1100, 23, -45, -89, 200, -429, -234, 485, 1, 9, 29};
    printf("Max subsequence sum is %d\n", maxSubsequenceSum(dataSet, sizeof(dataSet)/sizeof(dataSet[0])));
    printf("Max subsequence sum is %d\n", maxSubSequenceSumWithoutExtraBuffer(dataSet, sizeof(dataSet)/sizeof(dataSet[0])));
}
