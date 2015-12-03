/*
 * Stack utility.
 */

#include <stdlib.h>
#include "stackUtility.h"

void pushStack(StackNode*& top, int num)
{
    StackNode* tmpNode = (StackNode*)malloc(sizeof(StackNode));
    tmpNode->num = num;
    tmpNode->next = top;
    top = tmpNode;
}

int popStack(StackNode*& top)
{
    int value = 0xdeadbeaf;

    if (NULL != top)
    {
        value = top->num;
        StackNode* tmpNode = top;
        top = top->next;
        free(tmpNode);
    }

    return value;
}
