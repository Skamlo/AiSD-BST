#include <iostream>
#include <algorithm>

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

int getNodeHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int balanceCoefficient(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

void updateHeight(Node *node)
{
    node->height = 1 + std::max(getNodeHeight(node->left), getNodeHeight(node->right));
}