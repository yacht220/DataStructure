/*
 * Conduct string copy, and also need to consider the memory overlap between source and destination.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stringCopyOverlap(char* dst, const char* src, int size)
{
    if (NULL == dst || NULL == src)
    {
        return;
    }

    // src is before dst on start position, copy from back to front
    if (src < dst)
    {
        for (int i = size - 1; i >= 0; i--)
        {
            dst[i] = src[i];
        }    
    }
    // src is after dst on start position, copy from front to back
    else if (src > dst)
    {
        for (int i = 0; i < size; i++)
        {
            dst[i] = src[i];
        }
    }
}

int main(int argc, char** argv)
{
    char srcA[] = "Hello World! Goodbye Earth!";
    srcA[12] = '\0';
    char* dst = srcA + 8;

    printf("src is before dst.\nBefore copying, src = %s, dst = %s\n", srcA, dst);
    stringCopyOverlap(dst, srcA, 12);
    printf("After copying, src = %s, dst = %s\n\n", srcA, dst);

    char srcB[] = "Hello World! Goodbye Earth!";
    srcB[12] = '\0';
    dst = srcB;

    // src starts from srcB[8];
    printf("src is after dst.\nBefore copying, src = %s, dst = %s\n", &srcB[8], dst);
    stringCopyOverlap(dst, &srcB[8], 12);
    printf("After copying, src = %s, dst = %s\n\n", &srcB[8], dst);

    char srcC[] = "Hello World! Goodbye Earth!";
    dst = srcC;

    printf("src equals dst.\nBefore copying, src = %s, dst = %s\n", srcC, dst);
    stringCopyOverlap(dst, srcC, 12);
    printf("After copying, src = %s, dst = %s\n", srcC, dst);

    return 1;
}
