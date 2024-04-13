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

Node *insertNode(Node *root, int key)
{
    if (root == nullptr)
    {
        return createNode(key);
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

Node *constructAVL(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
    int median = 0.5 * (arr[(sizeOfArray - 1) / 2] + arr[sizeOfArray / 2]);
    Node *root = createNode(arr[median]);

    root->left = constructAVL(arr, start, median - 1);
    root->right = constructAVL(arr, median + 1, end);

    updateHeight(root);

    return root;
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