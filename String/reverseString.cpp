/*
 * Reverse a given string.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseString(char* str)
{
    if(NULL == str)
    {
        printf("Empty string.\n");
        return;
    }
    char* strTmp = str;
    char charTmp = '\0';
    int size = 0;

    while('\0' != *(strTmp))
    {
        size++;
        strTmp++;
    }
    strTmp--; 

    for(int i = 0; i < size/2; i++ )
    {
        charTmp = *strTmp;
        *strTmp = *str;
        *str = charTmp;
        str++;
        strTmp--;
    }
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Wrong input.\n");
        return -1;
    }

    reverseString(argv[1]);
    printf("%s\n", argv[1]);
}
