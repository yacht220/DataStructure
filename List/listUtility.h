#ifndef LIST_UTILITY_H
#define LIST_UTILILTY_H

/* Simply linked list */
typedef struct SimplyLinkedListNode
{
    int data;
    SimplyLinkedListNode* next;
}SimplyLinnkedListNode;

void printSimplyLinkedList(SimplyLinkedListNode* head);
SimplyLinkedListNode* initSimplyLinkedList(int array[], int size);
void insertNodeToSimplyLinkedList(SimplyLinkedListNode*& head, int value);
void deleteNodeFromSimplyLinkedList(SimplyLinkedListNode*& head, int value);

/* Doubly linked list */
struct DoublyLinkedListNode
{
    int num;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;
};

void insertNodeToRearOfDoublyLinkedList(DoublyLinkedListNode*& head, int num);
void deleteRearNodeInDoublyLinkedList(DoublyLinkedListNode*& head);

#endif
