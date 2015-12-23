/*
 * Calculate grestest common divisor for given 2 integers.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int calculateGrestestCommonDivisor(int numa, int numb)
{
    int divisor;
    int min;
    int result;

    if (numa < numb)
    {
        min = numa;
        divisor = sqrt(numa);
    }   
    else
    {
        min = numb;
        divisor = sqrt(numb);
    }

    if (1 == divisor)
    {
        divisor++;
    }
    
    while (divisor <= min)
    {
        if (0 == numa % divisor)
        {
            if (0 == numb % divisor)
            {
                break;
            }
        }

        divisor++;
    }

    divisor > min ? result = 1 : result = divisor;
    return result;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("2 parameters required!\n");
        return -1;
    }

    int numa = atoi(argv[1]);
    int numb = atoi(argv[2]);
    int result = calculateGrestestCommonDivisor(numa, numb);
    printf("Grestest common divisor (%d, %d) is %d.\n", numa, numb, result);

    return 1;
}
