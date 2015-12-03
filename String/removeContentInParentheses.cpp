/*
 * "abc(def(gh)ij" converts to "abc(defij".
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Stack/stackUtility.h"

void removeContentInParentheses(char* str)
{
    if (NULL == str)
    {
        return;
    } 

    StackNode* top = NULL;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int tmp = 0;

    while ('\0' != str[j])
    {
        if ('(' == str[j])
        {
            pushStack(top, i);
            if (i != j)
            {
                str[i] = str[j];
            }
            i++;
        }
        else if (')' == str[j])
        {
            tmp = popStack(top);
            if (0xdeadbeaf != tmp)
            {
                i = tmp;
            }
            else
            {
                if (i != j)
                {
                    str[i] = str[j];
                }
                i++;
            }
        }
        else
        {
            if (i != j)
            {
                str[i] = str[j];
            }
            i++;
        }

        j++;
    }

    str[i] = '\0';

    /* 
     * Not necessary to free the allocated memory of Stack in the end 
     * since the the allocated memory will be freed when this program process terminates. 
     */
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("1 string parameter required.\n");
        return -1;
    }

    removeContentInParentheses(argv[1]);
    printf("Result: %s\n", argv[1]);
}
