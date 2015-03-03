/*
 * Find the Nth maximum number in BST.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binaryTreeUtility.h"

int findNthMaxImp(Node *root, int &nth)
{
    static int sResult = 0;
    if(0 >= nth)
    {
        return sResult;
    }

    if(root)
    {
        findNthMaxImp(root->right, nth);  
        printf("%d, ", root->num);
        nth--;
        if(0 == nth)      
        {
            sResult = root->num;
	    return sResult;
        }
        findNthMaxImp(root->left, nth);
    }
    return sResult;
}

int findNthMaxNumber(Node *root, int nth)
{
    printf("Traverse BST with order right->parent->left.\n");
    return findNthMaxImp(root, nth);
}


int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("usage: <app>.exe <nth_max_num_index>\n");
        printf("       <nth_max_num_index> - 1...%d\n", ARRAY_SIZE);
        return -1;
    }
    char* inputNthMaxIndexChar = argv[1];
    int nthMax = atoi(inputNthMaxIndexChar);
    PNode root = NULL;
    int result = 0;
    
    if(nthMax <=0 || nthMax > ARRAY_SIZE)
    {
        printf("Please input <nth_max_num_index> with range 1...%d.\n", ARRAY_SIZE);
        return -1;
    }
    createBST(&root);
    result = findNthMaxNumber(root, nthMax);
    printf("\n\nThe %dth max number = %d", nthMax, result);
    
    return 1;
}
