/*
 * N=1: 1,1
 * N=2: 1,2,1
 * N=3: 1,3,3,1
 * N=4: 1,4,6,4,1
 * ...
 *
 * N=n: A[n,l] = A[n-1,l-1] + A[n-1,l]
 * size of N: n + 1
 *
 * Given N=n, provide the sequence pattern.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sequencePatternCalculation(int n)
{
    int* array = new int[n + 1];
   
    // Fill with 1 
    for (int i = 0; i < n + 1; i++)
    {
        array[i] = 1;
    }
      
    // Iterate rows except the 1st one
    for (int i = 1; i < n; i++)
    {
        // Iterate each element per row reversely. Skip the 1st and the last element.
        for (int j = i; j > 0; j--)
        {
            array[j] = array[j - 1] + array[j];
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
         printf("%d,", array[i]); 
    }
    printf("\n");

    delete[] array;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage! 1 parameter required!\n");
        return -1;
    }

    int n = atoi(argv[1]);
    sequencePatternCalculation(n);
    
    return 1;
}
