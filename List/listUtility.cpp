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

void deleteNodeFromSimplyLinkedList(Node*& head, int value)
{
    if (NULL == head)
    {
        printf("Empty list.\n");
        return;
    }

    Node* listPtr = head;

    if (head->data == value)
    {
        head = head->next;
        free(listPtr);
        return;
    }

    /* Find prev node */
    while (listPtr->next != NULL && listPtr->next->data != value)
    {
        listPtr = listPtr->next;
    }

    if (listPtr->next != NULL)
    {
        Node* targetNode = listPtr->next;
        listPtr->next = listPtr->next->next;
        free(targetNode);
    }
    else
    {
        printf("Node with value %d NOT found.\n", value);
    }
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
