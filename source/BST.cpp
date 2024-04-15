#include <iostream>
#include <vector>
#include "BST.h"

NodeBST *createNodeBST(int value)
{
    NodeBST *newNode = new NodeBST();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

NodeBST *insertBST(NodeBST *root, int key)
{
    if (root == nullptr)
    {
        return createNodeBST(key);
    }

    if (key < root->key)
    {
        root->left = insertBST(root->left, key);
    }

    else if (key >= root->key)
    {
        root->right = insertBST(root->right, key);
    }

    return root;
}

void inorderBST(NodeBST *root)
{
    if (root == nullptr)
        return;
    inorderBST(root->left);
    std::cout << root->key << "\t";
    inorderBST(root->right);
}

void postorderBST(NodeBST *root)
{
    if (root == nullptr)
        return;
    postorderBST(root->left);
    postorderBST(root->right);
    std::cout << root->key << "\t";
}

void preorderBST(NodeBST *root)
{
    if (root == nullptr)
        return;
    std::cout << root->key << "\t";
    preorderBST(root->left);
    preorderBST(root->right);
}

NodeBST *createBST(std::vector<int> &arr)
{
    NodeBST *root = nullptr;

    for (int i = 0; i < arr.size(); ++i)
    {
        root = insertBST(root, arr[i]);
    }
    return root;
}
