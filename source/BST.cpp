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

int bstToVine(NodeBST *grand)
{
    int count = 0;
    NodeBST *tmp = grand->right;
    while (tmp)
    {
        if (tmp->left)
        {
            NodeBST *oldTmp = tmp;
            tmp = tmp->left;
            oldTmp->left = tmp->right;
            tmp->right = oldTmp;
            grand->right = tmp;
        }
        else
        {
            count++;
            grand = tmp;
            tmp = tmp->right;
        }
    }

    return count;
}

void compress(NodeBST *grand, int m)
{
    NodeBST *tmp = grand->right;

    for (int i = 0; i < m; i++)
    {
        NodeBST *oldTmp = tmp;
        tmp = tmp->right;
        grand->right = tmp;
        oldTmp->right = tmp->left;
        tmp->left = oldTmp;
        grand = tmp;
        tmp = tmp->right;
    }
}

NodeBST *balanceBST(NodeBST *root)
{
    NodeBST *grand = createNodeBST(0);

    grand->right = root;

    int count = bstToVine(grand);
    int m = pow(2, log2(count + 1)) - 1;
    compress(grand, count - m);

    for (m = m / 2; m > 0; m /= 2)
    {
        compress(grand, m);
    }
    return grand->right;
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
