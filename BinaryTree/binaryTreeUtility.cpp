/*
 * Binary Tree Utility.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"

void insertBST(PNode* root, int value)
{
    PNode* ptrNode = NULL;

    if (NULL == *root)
    {
        *root = (PNode)malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->num = value;
    }
    else
    {
        ptrNode = root;
        while (NULL != *ptrNode)
        {
            if (value < (*ptrNode)->num)
            {
                ptrNode = &(*ptrNode)->left;
            }
            else
            {
                ptrNode = &(*ptrNode)->right;
            }
        }
        
        *ptrNode = (PNode)malloc(sizeof(Node));
        (*ptrNode)->left = NULL;
        (*ptrNode)->right = NULL;
        (*ptrNode)->num = value;
    }   
}

void createBST(PNode *t)
{        
    printf("Create binary search tree.\n");
    //int array[ARRAY_SIZE] = {5,2,1,4,7,8,3,6,9,10};
    //int array[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    //int array[ARRAY_SIZE] = {10,9,8,7,6,5,4,3,2,1};
    int array[ARRAY_SIZE] = {9,5,4,3,2,1,6,7,8,10};
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        insertBST(t, array[i]);
    }
}  

void preOrderBinaryTree(PNode root)
{
    if (NULL == root)
    {
        return;
    }

    printf("%d, ", root->num);
    preOrderBinaryTree(root->left);
    preOrderBinaryTree(root->right);
}

void inOrderBinaryTree(PNode root)
{
    if (NULL == root)
    {
        return;
    }

    inOrderBinaryTree(root->left);
    printf("%d, ", root->num);
    inOrderBinaryTree(root->right);
}

void postOrderBinaryTree(PNode root)
{
    if (NULL == root)
    {
        return;
    }

    postOrderBinaryTree(root->left);
    postOrderBinaryTree(root->right);
    printf("%d, ", root->num);
}

