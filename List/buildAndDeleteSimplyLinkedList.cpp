/*
 * Build a simply linked list from given array and delete some entry in that list.
 */

#include <stdlib.h>
#include <stdio.h>
#include "listUtility.h"

int main(int argc, char** argv)
{
    int array[] = {40, 2, 78, 1100, 23, 45, 89, 200, 429, 234, 485, 1, 9, 29};     
    SimplyLinkedListNode* head = initSimplyLinkedList(array, sizeof(array) / sizeof(array[0])); 
    int inputEntry;
    while (1)
    {
        printSimplyLinkedList(head);
        printf("Type the entry value you want to delete: ");
        scanf("%d", &inputEntry);
        deleteNodeFromSimplyLinkedList(head, inputEntry);
    }
    return 1;
}
