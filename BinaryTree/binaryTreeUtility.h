#ifndef BINARY_TREE_UTILITY_H
#define BINARY_TREE_UTILITY_H

#define ARRAY_SIZE 10

struct Node
{
  Node *left;
  Node *right;
  int longestDistanceToRootLeft; // For findLongestDistanceBetween2NodesInBinaryTree.cpp only.
  int longestDistanceToRootRight; // For findLongestDistanceBetween2NodesInBinaryTree.cpp only.
  int num;
};
typedef Node* PNode;

void insertBST(PNode* root, int value);
void createBST(PNode *t);
void preOrderBinaryTree(PNode root);
void inOrderBinaryTree(PNode root);
void postOrderBinaryTree(PNode root);

#endif
