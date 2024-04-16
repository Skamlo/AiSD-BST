#pragma once

#include <vector>

struct NodeAVL
{
public:
    int key;
    NodeAVL *left;
    NodeAVL *right;
    int height;
};

void updateHeight(NodeAVL *node);
int balanceCoefficient(NodeAVL *node);
NodeAVL *rightRotation(NodeAVL *node);
NodeAVL *leftRotation(NodeAVL *node);
NodeAVL *createAVL(std::vector<int> &arr, int start, int end);
void inorderAVL(NodeAVL *root);
void postorderAVL(NodeAVL *root);
void preorderAVL(NodeAVL *root);
bool checkIfKeyExistAVL(NodeAVL *root, int key);
NodeAVL *deleteNodeAVL(NodeAVL *root, int key);
void findMinMaxAVL(NodeAVL *node);
