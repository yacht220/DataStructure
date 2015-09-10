/*
 * Given preoder and inorder sequences, rebuild a Binary Tree.
 * Idea: First postion in preorder sequence is always the root node, then locate the position of root node in 
 * inorder sequence. Left sub sequence of root node is left child tree and right sub sequence of root node is 
 * right child tree in inorder sequence. The length of each child tree sequence in inorder sequence is equal 
 * to corresponding one in preorder sequence, where the left and right child tree sequences are continuous 
 * separately. Then do recursion on the left and right child tree sequences. The recursion quit condition is 
 * when there is only 1 item in sub sequence.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"

/**
 * @brief Rebuild a Binary Tree via given preorder and inorder sequences.
 *
 * @note Assume that the given preorder and inorder sequences are correce. 
 *
 * @param pre[]
 * @param in[]
 * @param preFirstIndex
 * @param inFirstIndex
 * @param length
 *
 * @return 
 */
Node* restoreBinaryTree(int pre[], int in[], int preFirstIndex, int inFirstIndex, int length)
{
    // It's empty.
    if (0 == length)
    {
        return NULL;
    }

    Node* node = new Node();
    node->num = pre[preFirstIndex];
    node->left = NULL;
    node->right = NULL;

    // It's leaf.
    if (1 == length)
    {
        return node;
    }
    
    // Find root in inorder sequence.
    int inRootIndex = inFirstIndex;
    while (in[inRootIndex] != pre[preFirstIndex])
    {
        inRootIndex++;
    }

    // Do the same on left and right child tree recursively.
    int lengthLeft = inRootIndex - inFirstIndex;
    int lengthRight = length - lengthLeft - 1;
    printf("lengthLeft = %d, lengthRight = %d\n", lengthLeft, lengthRight);
    node->left = restoreBinaryTree(pre, in, preFirstIndex + 1, inFirstIndex, lengthLeft);
    node->right = restoreBinaryTree(pre, in, preFirstIndex + lengthLeft + 1, inRootIndex + 1, lengthRight);

    return node;
}

int main(int argc, char** argv)
{
    int pre[] = {1, 2, 4, 6, 7, 3, 5};
    int in[] = {6, 4, 7, 2, 1, 5, 3};
    int length = sizeof(pre) / sizeof(pre[0]); // Length of preorder and inorder sequences are same.

    /*
     * The Binary Tree of given preorder and inorder sequences should be like below:
     *                    1
     *                   / \
     *                  2   3
     *                 /   /
     *                4   5
     *               / \
     *              6   7
     */

    printf("Given preorder sequence: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", pre[i]);
    }

    printf("\nGiven inorder sequence: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", in[i]);
    }

    printf("\nRebuilding Binary Tree...\n");
    Node* root = restoreBinaryTree(pre, in, 0, 0, length);
    
    printf("After rebuilding...\nPreorder sequence: ");
    preOrderBinaryTree(root);
    
    printf("\nInorder sequence: ");
    inOrderBinaryTree(root);

    printf("\nPostorder sequence: ");
    postOrderBinaryTree(root);

    printf("\n");
}
