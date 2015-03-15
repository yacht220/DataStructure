/*
 * List utility.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listUtility.h"

void insertNodeToSimplyLinkedList(Node*& head, int value)
{
    if(NULL == head)
    {
        printf("Empty simply linked list. Create a head.\n");
        head = (Node*)malloc(sizeof(Node));
	head->data = value;
	head->next = NULL;
        return;
    }

    Node* curPtr = head;
    while(NULL != curPtr->next)
    {
        curPtr = curPtr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    curPtr->next = newNode;
}

Node* initSimplyLinkedList(int array[], int size)
{
    Node* head = NULL;
    for(int i = 0; i < size; i++)
    {
        insertNodeToSimplyLinkedList(head, array[i]);
    }
    return head;
}

void printSimplyLinkedList(Node* head)
{
    if(NULL == head)
    {
        printf("Empty list.\n");
	return;
    }

    Node* cur = head;
    while(NULL != cur)
    {
        printf("%d, ", cur->data);
	cur = cur->next;
    }
    printf("\n");
}
