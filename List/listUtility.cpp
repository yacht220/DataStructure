/*
 * List utility.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listUtility.h"

void insertNodeToSimplyLinkedList(SimplyLinkedListNode*& head, int value)
{
    if (NULL == head)
    {
        printf("Empty simply linked list. Create a head.\n");
        head = (SimplyLinkedListNode*)malloc(sizeof(SimplyLinkedListNode));
        head->data = value;
        head->next = NULL;
        return;
    }

    SimplyLinkedListNode* curPtr = head;
    while (NULL != curPtr->next)
    {
        curPtr = curPtr->next;
    }
    SimplyLinkedListNode* newNode = (SimplyLinkedListNode*)malloc(sizeof(SimplyLinkedListNode));
    newNode->data = value;
    newNode->next = NULL;
    curPtr->next = newNode;
}

void deleteNodeFromSimplyLinkedList(SimplyLinkedListNode*& head, int value)
{
    if (NULL == head)
    {
        printf("Empty list.\n");
        return;
    }

    SimplyLinkedListNode* listPtr = head;

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
        SimplyLinkedListNode* targetNode = listPtr->next;
        listPtr->next = listPtr->next->next;
        free(targetNode);
    }
    else
    {
        printf("Node with value %d NOT found.\n", value);
    }
}

SimplyLinkedListNode* initSimplyLinkedList(int array[], int size)
{
    SimplyLinkedListNode* head = NULL;
    for (int i = 0; i < size; i++)
    {
        insertNodeToSimplyLinkedList(head, array[i]);
    }
    return head;
}

void printSimplyLinkedList(SimplyLinkedListNode* head)
{
    if (NULL == head)
    {
        printf("Empty list.\n");
        return;
    }

    SimplyLinkedListNode* cur = head;
    while (NULL != cur)
    {
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void insertNodeToRearOfDoublyLinkedList(DoublyLinkedListNode*& head, int num)
{
    if (NULL == head)
    {
        head = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
        head->num = num;
        head->prev = NULL;
        head->next = NULL;
    }
    else
    {
        DoublyLinkedListNode* tmpNode = head;
        DoublyLinkedListNode* newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
        newNode->num = num;
        newNode->next = NULL;
        while (NULL != tmpNode->next)
        {
            tmpNode = tmpNode->next;
        }
        tmpNode->next = newNode;
        newNode->prev = tmpNode;
    }
}

void deleteRearNodeInDoublyLinkedList(DoublyLinkedListNode*& head)
{
    if (NULL != head)
    {
        DoublyLinkedListNode* tmpNode = head;
        while (NULL != tmpNode->next)
        {
            tmpNode = tmpNode->next;
        }
        if (head == tmpNode)
        {
            free(tmpNode);
            head = NULL;
        }
        else
        {
            tmpNode = tmpNode->prev;
            free(tmpNode->next);
            tmpNode->next = NULL;
        }
    }
}
