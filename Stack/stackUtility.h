#ifndef STACK_UTILITY_H
#define STACK_UTILITY_H

struct StackNode
{
    int num;
    StackNode* next;
};

void pushStack(StackNode*& top, int num);
int popStack(StackNode*& top);

#endif // STACK_UTILITY_H
