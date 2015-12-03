/*
 * Find all paths in Binary Tree whose sum equals to given number.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"
#include "../List/listUtility.h"
/* It could use stack instead of doubly linked list */
//#include "../Stack/stackUtility.h"

void findAllPathsWithGivenSum(const Node* root, int givenSum)
{
    static int sumRecord = 0;
    static bool foundFlag = false;
    static DoublyLinkedListNode* headOfDoublyLinkedListForBinaryTreeNode = NULL;

    if (NULL == root)
    {
        return;
    }

    sumRecord += root->num;
    if (sumRecord > givenSum)
    {
        printf("Current sum is greater than given sum. Give up this path.\n");
        sumRecord -= root->num;
        return;
    }

    insertNodeToRearOfDoublyLinkedList(headOfDoublyLinkedListForBinaryTreeNode, root->num);

    if (sumRecord == givenSum && NULL == root->left && NULL == root->right)
    {
        printf("Path found: ");
        foundFlag = true;
        DoublyLinkedListNode* it = headOfDoublyLinkedListForBinaryTreeNode;
        while (NULL != it->next)
        {
            printf("%d, ", it->num);
            it = it->next;
        }
        printf("%d\n", it->num);
        deleteRearNodeInDoublyLinkedList(headOfDoublyLinkedListForBinaryTreeNode);
        sumRecord -= root->num;
        return;
    }

    findAllPathsWithGivenSum(root->left, givenSum);
    findAllPathsWithGivenSum(root->right, givenSum);

    deleteRearNodeInDoublyLinkedList(headOfDoublyLinkedListForBinaryTreeNode);
    sumRecord -= root->num;

    if (0 == sumRecord && false == foundFlag)
    {
        printf("NO path found.\n");
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Wrong usage.\n");
        return -1;
    }
    int givenSum = atoi(argv[1]);
    Node* root = NULL;
    createBST(&root);
    findAllPathsWithGivenSum(root, givenSum);
    return 1;
}
