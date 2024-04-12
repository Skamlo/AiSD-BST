#include <iostream>

// konstruowanie drzewa BST

struct Node
{
    int key;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->key = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return createNode(key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }

    else if (key >= root->key)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// funkcje odpowidzialne za trawersowanie

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

Node *createBST(int arr[], int n)
{
    Node *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        root = insert(root, arr[i]);
    }
    return root;
}