#include <iostream>
#include <vector>
#include <cmath>
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

bool checkIfKeyExistBST(NodeBST *root, int key)
{
    if (root == nullptr)
        return false;
    return (root->key == key) || checkIfKeyExistBST(root->left, key) || checkIfKeyExistBST(root->right, key);
}

NodeBST *deleteNodeBST(NodeBST *root, int key)
{
    if (root == NULL)
        return root;

    if (root->key > key)
    {
        root->left = deleteNodeBST(root->left, key);
        return root;
    }
    else if (root->key < key)
    {
        root->right = deleteNodeBST(root->right, key);
        return root;
    }

    if (root->left == NULL)
    {
        NodeBST *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        NodeBST *temp = root->left;
        delete root;
        return temp;
    }

    else
    {

        NodeBST *succParent = root;
        NodeBST *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->key = succ->key;

        delete succ;
        return root;
    }
}

// REBALANSOWANIE NIE DZIALA: SEG. FAULT

NodeBST *rotateRight(NodeBST *node)
{
    NodeBST *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

NodeBST *rotateLeft(NodeBST *node)
{
    NodeBST *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
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
