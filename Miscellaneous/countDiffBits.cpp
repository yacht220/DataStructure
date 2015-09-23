/*
 * Count the number of different bits for a given 2 variables in binary format.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

template<typename T>
int countDiffBits(T varA, T varB)
{
    int counter = 0;
    T varC = varA & varB;
    varC != varC;

    for (int i = 0; i < sizeof(T) * 8; i++)
    {
        counter += varC & 0x1;
        varC >>= 1;
    }
    
    return counter;
}

int main(int argc, char** argv)
{
    int varA = 0xDEADBEAF;
    int varB = 0xBEAFDEAD;
    int counter = countDiffBits(varA, varB);
    printf("Number of different bits between %p and %p are %d.\n", varA, varB, counter);
    return 1;
}
