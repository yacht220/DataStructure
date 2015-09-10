/*
 * Find all paths in a Binary Tree where the sum of nodes in the path equal to a given number. 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"

void printPath(int stack[], int top)
{
    /*while (0 != top)
      {
      printf("%d, ", stack[--top]);
      }*/

    if (top > 0)
    {
        for (int i = 0; i < top; i++)
        {
            printf("%d, ", stack[i]);
        }
    }
    printf("\n");
}

void findPathEqual2Sum(Node* root, int sum, int stack[], int top)
{
    stack[top++] = root->num;
    sum -= root->num;

    if (NULL == root->left && NULL == root->right)
    {
        if (0 == sum)
        {
            printPath(stack, top);
        }
    }
    else
    {
        if (NULL != root->left)
        {
            findPathEqual2Sum(root->left, sum, stack, top);
        }	
        if (NULL != root->right)
        {
            findPathEqual2Sum(root->right, sum, stack, top);
        }
    }
    sum += root->num;
    top--;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    { 
        printf("usage: <app>.exe <sum>\n");
        return -1;
    }
    char* sumChar = argv[1];
    int sum = atoi(sumChar);
    Node* root = NULL;
    int stack[ARRAY_SIZE];
    /* Reuse BST creation since BST is a kind of Binary Tree. */
    createBST(&root); 
    findPathEqual2Sum(root, sum, stack, 0);
}
