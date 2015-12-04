/*
 * "aabbbbc" converts to "abc".
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void removeDuplicateNeighbourChar(char* str)
{
    if (NULL == str || '\0' == *str)
    {
        return;
    }

    unsigned int i = 0;
    unsigned int j = 1;

    while ('\0' != str[j])
    {
        if (str[i] != str[j])
        {
            i++;
            if (i != j)
            {
                str[i] = str[j];
            }
        }
        j++;	
    }

    i++;
    str[i] = '\0';
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("1 string parameter required.\n");
        return -1;
    }

    removeDuplicateNeighbourChar(argv[1]);
    printf("Result: %s\n", argv[1]);
    
    return 1;
}
