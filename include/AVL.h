# pragma once

#include <vector>

struct NodeAVL
{
    int key;
    NodeAVL *left;
    NodeAVL *right;
    int height;
};

NodeAVL *createAVL(std::vector<int> &arr, int start, int end);
void inorderAVL(NodeAVL *root);
void postorderAVL(NodeAVL *root);
void preorderAVL(NodeAVL *root);
