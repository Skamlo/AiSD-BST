# pragma once

#include <vector>

struct NodeBST
{
    int key;
    NodeBST *left;
    NodeBST *right;
};

NodeBST *createBST(std::vector<int> &arr);
void inorderBST(NodeBST *root);
void postorderBST(NodeBST *root);
void preorderBST(NodeBST *root);
