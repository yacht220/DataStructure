/*
 * Find all paths in Binary Tree whose sum equals to given number.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"

/*struct StackNode
  {
  int num;
  StackNode* next;
  };

  void pushStack(StackNode*& top, int num)
  {
  StackNode* tmpNode = (StackNode*)malloc(sizeof(StackNode));
  tmpNode->num = num;
  tmpNode->next = top;
  top = tmpNode;
  }

  void popStack(StackNode*& top)
  {
  if (NULL != top)
  {
  StackNode* tmpNode = top;
  top = top->next;
  free(tmpNode);
  }
  }*/

struct DoublyLinkedListNode
{
    int num;
    DoublyLinkedListNode* prev;
    DoublyLinkedListNode* next;
};

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
