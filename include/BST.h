#pragma once

#include <vector>

struct NodeBST
{
public:
    int key;
    NodeBST *left;
    NodeBST *right;
};

NodeBST *createBST(std::vector<int> &arr);
void inorderBST(NodeBST *root);
void postorderBST(NodeBST *root);
void preorderBST(NodeBST *root);
bool checkIfKeyExistBST(NodeBST *root, int key);
NodeBST *deleteNodeBST(NodeBST *root, int key);
void findMinMaxBST(NodeBST *node);
NodeBST *rotateRight(NodeBST *node);
NodeBST *rotateLeft(NodeBST *node);