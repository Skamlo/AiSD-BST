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

NodeBST *createBST(std::vector<int> &arr)
{
    NodeBST *root = nullptr;

    for (int i = 0; i < arr.size(); ++i)
    {
        root = insertBST(root, arr[i]);
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

void rotateRight(NodeBST *&grand, NodeBST *&tmp)
{
    NodeBST *oldTmp = tmp;
    tmp = tmp->left;
    oldTmp->left = tmp->right;
    tmp->right = oldTmp;
    grand->right = tmp;
}

void rotateLeft(NodeBST *&grand, NodeBST *&tmp)
{
    NodeBST *oldTmp = tmp;
    tmp = tmp->right;
    grand->right = tmp;
    oldTmp->right = tmp->left;
    tmp->left = oldTmp;
    grand = tmp;
    tmp = tmp->right;
}

int bstToVine(NodeBST *grand)
{
    int count = 0;
    NodeBST *tmp = grand->right;
    while (tmp)
    {
        if (tmp->left)
        {
            rotateRight(grand, tmp);
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

void makeRotationsToReduceHeight(NodeBST *grand, int numberOfNodes)
{
    NodeBST *tmp = grand->right;
    for (int i = 0; i < numberOfNodes; i++)
    {
        rotateLeft(grand, tmp);
    }
}

NodeBST *balanceBST(NodeBST *root)
{
    // in this version of algorithm, dummy root is created and actual root is asigned as right child
    NodeBST *grand = createNodeBST(0);
    grand->right = root;

    int count = bstToVine(grand);
    int numberOfNodes = pow(2, log2(count + 1)) - 1;
    makeRotationsToReduceHeight(grand, count - numberOfNodes);

    for (numberOfNodes = numberOfNodes / 2; numberOfNodes > 0; numberOfNodes /= 2)
    {
        makeRotationsToReduceHeight(grand, numberOfNodes);
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
