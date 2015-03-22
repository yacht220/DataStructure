/*
 * Print Fibonacci numbers with given length.
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/**
 * @brief Very inefficient recursion algorithm.
 * @param nth - Nth number in Fib. Start with 1.
 */
unsigned int fibRecursion(int nth, unsigned int fibArray[])
{
    if (nth <= 2)
    {
        fibArray[nth - 1] = 1;
        return 1;
    }
    else
    {
        return fibArray[nth - 1]  = fibRecursion(nth - 2, fibArray) + fibRecursion(nth - 1, fibArray);
    }
}

/**
 * @brief Optimized without recursion.
 * @param lengthOfFib - Length of the Fib. Start with 1.
 */
void fibNonRecursion(int lengthOfFib, unsigned int fibArray[])
{
    int prevIndex;
    int prevOfPrevIndex;
    for (int i = 0; i < lengthOfFib; i++)
    {        
        if (i < 2)
        {
            fibArray[i] = 1;
        }
        else
        {
            prevIndex = i - 1;
            prevOfPrevIndex = prevIndex - 1;
            fibArray[i] = fibArray[prevIndex] + fibArray[prevOfPrevIndex];
        }

    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage.\n");
        return -1;
    }

    int size = atoi(argv[1]);
    unsigned int* fibArray = (unsigned int*)malloc(sizeof(unsigned int) * size);
    memset(fibArray, 0, sizeof(unsigned int) * size);
    //fibRecursion(size, fibArray);
    fibNonRecursion(size, fibArray);
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", fibArray[i]);
    }
}
