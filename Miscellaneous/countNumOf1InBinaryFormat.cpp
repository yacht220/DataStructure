/*
 * Count the number of "1" for a given variable in binary format.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

template<typename T>
int countNumOf1InBinaryFormat(T var)
{
    int counter = 0;
    for (int i = 0; i < sizeof(T) * 8; i++)
    {
        counter += var & 0x1;
        var = var >> 1;
    }

    return counter;
}

int main(int argc, char** argv)
{
    int var = 0xDEADBEAF;
    int counter = countNumOf1InBinaryFormat(var);
    printf("Number of \"1\" is %d.\n", counter);
    return 1;
}
