/*
 * Check if it's prime number.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

bool checkPrimeNumber(int num)
{
    int divider = sqrt(num);
    printf("divider = %d.\n", divider);

    while (0 != num % divider && 1 < divider)
    {
        divider--;
    }

    if (1 == divider)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage! 1 parameter required!\n");
        return -1;
    }

    int num = atoi(argv[1]);
    if (checkPrimeNumber(num))
    {
        printf("Prime\n");
    }
    else
    {
        printf("NOT prime\n");
    }
    
    return 1;
}
