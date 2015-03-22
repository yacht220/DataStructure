#ifndef LIST_UTILITY_H
#define LIST_UTILILTY_H

typedef struct Node
{
    int data;
    Node* next;
}Node;

void printSimplyLinkedList(Node* head);
Node* initSimplyLinkedList(int array[], int size);
void insertNodeToSimplyLinkedList(Node*& head, int value);
void deleteNodeFromSimplyLinkedList(Node*& head, int value);

#endif
