/*
 * Find the longest distance between 2 nodes in given Binary Tree.
 *
 * Analysis:
 * 1. The endpoints of the longest distance path could be leaf node <--> leaf node or leaf node <--> root node.
 * 2. There are 2 situations where the longest distance path exists, through the root or not:
 *               A                                  A
 *              / \                                / \
 *             B   C                              B   C
 *            / \   \                            / \
 *           D   E   F                          D   E
 *              /   /                          /     \
 *             G   H                          F       G
 *                                           /         \
 *                                          H           I
 *    G <--> H through root A              H <--> I not through root A
 *
 * Solution:
 * Traverse each node, treat each node as root for subtree, find the longest distance through
 * the root for each subtree. The maximum value among these longest distances through root 
 * is the answer.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtilityRecursion.h"

/*
 * It's the solution to find the longest distance through the root in Binary Tree. 
 * But it's not suitable to find the longest distance in Binary Tree. 
 */
/*void findLongestDistanceThroughRoot(PNode root)
{
    static int longestDistanceLeft = 0;
    static int longestDistance = 0;
    static int distanceCounter = -1;

    distanceCounter++;

    if (NULL == root)
    {
        if (0 == distanceCounter)
        {
            printf("Tree is empty.\n");
        }
        return;
    }
    
    if (distanceCounter > longestDistance)
    {
        longestDistance = distanceCounter;
    }

    findLongestDistanceThroughRoot(root->left);
    distanceCounter--;

    // Back to root of entire tree again and ready to process right subtree.
    if (0 == distanceCounter)
    {
        longestDistanceLeft = longestDistance;
        longestDistance = 0;
    }

    findLongestDistanceThroughRoot(root->right);
    distanceCounter--;

    // Back to root of entire tree again and finish.
    if (0 == distanceCounter)
    {
        longestDistance += longestDistanceLeft;
        printf("The longest distance between 2 nodes in Binary Tree is %d.\n", longestDistance);
    }
}*/

/*
 * We have better solution below.
 */
int findLongestDistance(Node* root)
{
    /*
     * It's postorder traverse.
     */

    static int max = 0;

    if (NULL == root)
    {
        return -1;
    }

    findLongestDistance(root->left);
    findLongestDistance(root->right);

    // Calculate longest distance to current root from both left and right.
    if (NULL == root->left)
    {
        root->longestDistanceToRootLeft = 0;
    }
    else if (root->left->longestDistanceToRootLeft > root->left->longestDistanceToRootRight)
    {
        root->longestDistanceToRootLeft = root->left->longestDistanceToRootLeft + 1;
    }
    else 
    {
        root->longestDistanceToRootLeft = root->left->longestDistanceToRootRight + 1;
    }

    if (NULL == root->right)
    {
        root->longestDistanceToRootRight = 0;
    }
    else if (root->right->longestDistanceToRootLeft > root->right->longestDistanceToRootRight)
    {
        root->longestDistanceToRootRight = root->right->longestDistanceToRootLeft + 1;
    }
    else
    {
        root->longestDistanceToRootRight = root->right->longestDistanceToRootRight + 1;
    }

    // Update the maximum value of longest distance throught root so far.
    if (max < root->longestDistanceToRootLeft + root->longestDistanceToRootRight)
    {
        max = root->longestDistanceToRootLeft + root->longestDistanceToRootRight;
    }    

    return max;
}

int main(int argc, char** argv)
{
    int array[ARRAY_SIZE] = {9,5,4,3,2,1,6,7,8,10};
    Node* root = createBST(array, sizeof(array)/sizeof(array[0]));
    //findLongestDistanceThroughRoot(root);
    int longestDistance = findLongestDistance(root);    
    printf("The longest distance between 2 nodes in Binary Tree is %d.\n", longestDistance);
    return 1;
}
