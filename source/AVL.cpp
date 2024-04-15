#include <iostream>
#include <algorithm>
#include <vector>
#include "AVL.h"


NodeAVL *createNodeAVL(int value)
{
    NodeAVL *newNode = new NodeAVL();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}


int getNodeHeight(NodeAVL *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}


int balanceCoefficient(NodeAVL *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}


void updateHeight(NodeAVL *node)
{
    node->height = 1 + std::max(getNodeHeight(node->left), getNodeHeight(node->right));
}


NodeAVL *rightRotation(NodeAVL *node)
{
    NodeAVL *newroot = node->left;
    node->left = newroot->right;
    newroot->right = node;

    updateHeight(node);
    updateHeight(newroot);

    return newroot;
}


NodeAVL *leftRotation(NodeAVL *node)
{
    NodeAVL *newroot = node->right;
    node->right = newroot->left;
    newroot->left = node;

    updateHeight(node);
    updateHeight(newroot);

    return newroot;
}


NodeAVL *insertNode(NodeAVL *root, int key)
{
    if (root == nullptr)
    {
        return createNodeAVL(key);
    }

    if (key < root->key)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insertNode(root->right, key);
    }
    else
    {
        return root;
    }

    updateHeight(root);

    int balanceCoef = balanceCoefficient(root);

    // LL case
    if (balanceCoef > 1 && key < root->left->key)
    {
        return rightRotation(root);
    }

    // RR case
    if (balanceCoef < -1 && key > root->right->key)
    {
        return leftRotation(root);
    }

    // LR case
    if (balanceCoef > 1 && key > root->left->key)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    // RL case
    if (balanceCoef < -1 && key < root->right->key)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}


NodeAVL *createAVL(std::vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int median = (start + end) / 2;
    NodeAVL *root = createNodeAVL(arr[median]);

    root->left = createAVL(arr, start, median - 1);
    root->right = createAVL(arr, median + 1, end);

    updateHeight(root);

    return root;
}


void inorderAVL(NodeAVL *root)
{
    if (root == nullptr)
        return;
    inorderAVL(root->left);
    std::cout << root->key << " ";
    inorderAVL(root->right);
}


void postorderAVL(NodeAVL *root)
{
    if (root == nullptr)
        return;
    postorderAVL(root->left);
    postorderAVL(root->right);
    std::cout << root->key << " ";
}


void preorderAVL(NodeAVL *root)
{
    if (root == nullptr)
        return;
    std::cout << root->key << " ";
    preorderAVL(root->left);
    preorderAVL(root->right);
}