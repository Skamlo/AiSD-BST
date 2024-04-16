#include <iostream>
#include <string>
#include "AVL.h"
#include "BST.h"
#include "menuFunctions.h"


// Menu
std::string stringToLowercase(std::string text)
{
    for (auto &x : text)
    {
        x = tolower(x);
    }

    return text;
}


bool textValidation(std::string *numbers)
{
    std::string newNumbers;
    int lastIndex = -1;
    for (int i = 0; i < numbers->size(); i++)
    {
        if ((*numbers)[i] == ' ')
        {
            if (lastIndex != -1)
            {
                if (newNumbers[lastIndex] != ' ')
                {
                    newNumbers += ' ';
                    lastIndex += 1;
                }
            }
        }
        else if ((*numbers)[i] >= '0' && (*numbers)[i] <= '9')
        {
            newNumbers += (*numbers)[i];
            lastIndex += 1;
        }
        else
        {
            return false;
        }
    }
    *numbers = newNumbers;
    return true;
}


int strToInt(std::string numberString)
{
    int numberInt = 0;
    for (int i=0; i<numberString.length(); i++)
    {
        numberInt *= 10;
        numberInt += numberString[i] - '0';
    }
    return numberInt;
}


void convertNodes(std::vector<int> *nodes, std::string numbers)
{
    int currentNumber = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == ' ')
        {
            nodes->push_back(currentNumber);
            currentNumber = 0;
        }
        else if (numbers[i] >= '0' && numbers[i] <= '9')
        {
            currentNumber = currentNumber * 10 + (numbers[i] - '0');
        }
    }
    nodes->push_back(currentNumber);
}


// FindMinMax
int findMinBST(NodeBST *node)
{
    NodeBST *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->key;
}


int findMaxBST(NodeBST *node)
{
    NodeBST *current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current->key;
}


void findMinMaxBST(NodeBST *root)
{
    int min = findMinBST(root);
    int max = findMaxBST(root);
    std::cout << "Min: " << min << std::endl
              << "Max: " << max << std::endl;
}


int findMinAVL(NodeAVL *node)
{
    NodeAVL *current = node;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->key;
}


int findMaxAVL(NodeAVL *node)
{
    NodeAVL *current = node;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current->key;
}


void findMinMaxAVL(NodeAVL *root)
{
    int min = findMinAVL(root);
    int max = findMaxAVL(root);
    std::cout << "Min: " << min << std::endl
              << "Max: " << max << std::endl;
}


// Print
void printBST(NodeBST *root)
{
    std::cout << "  In-order: ";
    inorderBST(root);
    std::cout << std::endl
              << "Post-order: ";
    postorderBST(root);
    std::cout << std::endl
              << " Pre-order: ";
    preorderBST(root);
    std::cout << std::endl;
}


void printAVL(NodeAVL *root)
{
    std::cout << "  In-order: ";
    inorderAVL(root);
    std::cout << std::endl
              << "Post-order: ";
    postorderAVL(root);
    std::cout << std::endl
              << " Pre-order: ";
    preorderAVL(root);
    std::cout << std::endl;
}


// Delete
bool checkIfKeyExistBST(NodeBST* root, int key)
{
    if (root == nullptr)
        return false;
    return (root->key == key) || checkIfKeyExistBST(root->left, key) || checkIfKeyExistBST(root->right, key);
}


bool checkIfKeyExistAVL(NodeAVL* root, int key)
{
    if (root == nullptr)
        return false;
    return (root->key == key) || checkIfKeyExistAVL(root->left, key) || checkIfKeyExistAVL(root->right, key);
}


NodeBST* deleteNodeBST(NodeBST* root, int key)
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
        NodeBST* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        NodeBST* temp = root->left;
        delete root;
        return temp;
    }

    else {
 
        NodeBST* succParent = root;
        NodeBST* succ = root->right;
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


NodeAVL* minValueNode(NodeAVL* node) 
{
    NodeAVL* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}


NodeAVL* deleteNodeAVL(NodeAVL* root, int key) 
{ 
    if (root == NULL) 
        return root; 

    if (key < root->key) 
    {
        root->left = deleteNodeAVL(root->left, key);
    }
    else if(key > root->key) 
    {
        root->right = deleteNodeAVL(root->right, key);
    }
    else
    {
        if((root->left == NULL) || (root->right == NULL)) 
        { 
            NodeAVL* temp;
            if (root->left)
                temp = root->left;
            else
                temp = root->right;
 
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else
            {
                *root = *temp;
            }
            
            free(temp); 
        } 
        else
        { 
            NodeAVL* temp = minValueNode(root->right); 
            root->key = temp->key; 
            root->right = deleteNodeAVL(root->right, temp->key); 
        } 
    } 
 
    if (root == NULL)
        return root;

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
