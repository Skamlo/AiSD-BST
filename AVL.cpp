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

Node *rightRotation(Node *node)
{
    Node *newroot = node->left;
    node->left = newroot->right;
    newroot->right = node;

    updateHeight(node);
    updateHeight(newroot);

    return newroot;
}

Node *leftRotation(Node *node)
{
    Node *newroot = node->right;
    node->right = newroot->left;
    newroot->left = node;

    updateHeight(node);
    updateHeight(newroot);

    return newroot;
}

void inorder(Node *root)
{
    if (root = nullptr)
    {
        return;
    }
    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root = nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    std::cout << root->key << " ";
}

void preorder(Node *root)
{
    if (root = nullptr)
    {
        return;
    }
    std::cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}