/*
 * Binary Tree Utility Recursion.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtilityRecursion.h"

PNode insertBST(PNode root, int value)
{
    if (NULL == root)
    {
        root = (PNode)malloc(sizeof(Node));
        root->left = NULL;
        root->right = NULL;
        root->num = value;
        return root;
    }

    if (root->num >= value)
    {
        root->left = insertBST(root->left, value);
    } else
    {
        root->right = insertBST(root->right, value);
    }

    return root;
}

PNode createBST(int array[], int size)
{        
    printf("Create binary search tree\n");
    PNode root = NULL;
    for (int i = 0; i < size; i++)
    {
        printf("Element %u\n", array[i]);
        root = insertBST(root, array[i]);
    }
    return root;
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

