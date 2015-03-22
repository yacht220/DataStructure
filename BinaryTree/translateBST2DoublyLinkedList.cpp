/*
 * Translate BST to Doubly-Linked List.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"

void translateBST2DoublyLinkedList(Node* root, Node*& head, Node*& tail)
{
    Node* leftTailTmp = NULL;
    Node* rightHeadTmp = NULL;

    if(NULL == root)
    {
        head = NULL;
        tail = NULL;
        return;
    }

    translateBST2DoublyLinkedList(root->left, head, leftTailTmp);
    translateBST2DoublyLinkedList(root->right, rightHeadTmp, tail);

    if(NULL != leftTailTmp)
    {
        root->left = leftTailTmp;
        leftTailTmp->right = root;
    }
    else
    {
        head = root;
    }

    if(NULL != rightHeadTmp)
    {
        root->right = rightHeadTmp;
        rightHeadTmp->left = root;
    }
    else
    {
        tail = root;
    }
}

void traverseDoublyLinkedList(Node* head, Node* tail)
{
    while(head != tail)
    {
        printf("%d, ", head->num);
        head = head->right;
    }
    printf("%d\n", head->num);
}

int main(int argc, char **argv)
{
    Node* root = NULL;
    Node* head = NULL;
    Node* tail = NULL;

    createBST(&root);
    translateBST2DoublyLinkedList(root, head, tail);
    traverseDoublyLinkedList(head, tail); 
    return 1;
}
