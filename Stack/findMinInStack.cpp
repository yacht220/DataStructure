/*
 * Define a Stack data structure, define a min function which could retrieve the minimum element in  * Stack. The order of complexity for push, pop and min function should be O(1). 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StackElement
{
    int data;
    int min;
};

struct Stack
{
    StackElement* array;
    int size;
    int top;
};

void initStack(Stack& stack, int maxSize)
{
    stack.array = (StackElement*)malloc(sizeof(StackElement) * maxSize);
    stack.size = maxSize;
    stack.top = 0;
}

void pushStack(Stack& stack, int value)
{
    if(stack.top == stack.size)
    {
        printf("Out of size.\n");
        return;
    }
    stack.array[stack.top].data = value;
    if(0 == stack.top)
    {
        stack.array[stack.top].min = value;
    }
    else
    {
        if(stack.array[stack.top - 1].min > value)
	{
	    stack.array[stack.top].min = value;
	}
	else
	{
	    stack.array[stack.top].min = stack.array[stack.top - 1].min;
	}
    }
    stack.top++;
}

int popStack(Stack& stack)
{
    if(0 == stack.top)
    {
        printf("Empty stack.\n");
	return -1;
    }
    stack.top--;
    return stack.array[stack.top].data;
}

int findMinInStack(Stack stack)
{
    if(0 == stack.top)
    {
        printf("Empty stack.\n");
	return -1;
    }
    return stack.array[stack.top-1].min;
}

int main(int argc, char** argv)
{
    Stack stack;
    initStack(stack, 100);
    int dataSet[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    for(int i = 0; i < (sizeof(dataSet)/sizeof(dataSet[0])); i++)
    {
        pushStack(stack, dataSet[i]);   
    }
    printf("Min value in Stack: %d\n", findMinInStack(stack));
}
