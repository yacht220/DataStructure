/*
 * Reverse a given simply linked list.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listUtility.h"

void reverseSimplyLinkedList(SimplyLinkedListNode*& head)
{
    if (NULL == head)
    {
        printf("Empty list.\n");
        return;
    }

    if (NULL == head->next)
    {
        printf("Only one node in list.\n");
        return;
    }

    SimplyLinkedListNode* cur = head;
    SimplyLinkedListNode* prev = NULL;
    SimplyLinkedListNode* nex = cur->next;

    while (NULL != nex)
    {
        cur->next = prev;
        prev = cur;
        cur = nex;
        nex = cur->next;
    }

    cur->next = prev;
    head = cur;
}

SimplyLinkedListNode* reverseSimplyLinkedListRecursion(SimplyLinkedListNode* head)
{
    if (NULL == head || NULL == head->next)
    {
        return head;
    }

    SimplyLinkedListNode* newHead = reverseSimplyLinkedListRecursion(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};
    SimplyLinkedListNode* head = initSimplyLinkedList(array, sizeof(array)/sizeof(array[0]));
    printf("Before reverse.\n");
    printSimplyLinkedList(head);
    //reverseSimplyLinkedList(head);
    SimplyLinkedListNode* newHead = reverseSimplyLinkedListRecursion(head);
    printf("After reverse.\n");
    //printSimplyLinkedList(head);
    printSimplyLinkedList(newHead);
}

