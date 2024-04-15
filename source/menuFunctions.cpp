#include <iostream>
#include "AVL.h"
#include "BST.h"
#include "menuFunctions.h"

#define HIGH_VALUE 1000000000
#define LOW_VALUE -1000000000


int findMinBST(NodeBST *node)
{
    NodeBST *current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->key;
}


int findMaxBST(NodeBST *node)
{
    NodeBST *current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->key;
}


void findMinMaxBST(NodeBST *root)
{
    int min = findMinBST(root);
    int max = findMaxBST(root);
    std::cout << "Min: " << min << std::endl << "Max: " << max << std::endl;
}


int findMinAVL(NodeAVL *node)
{
    NodeAVL *current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->key;
}


int findMaxAVL(NodeAVL *node)
{
    NodeAVL *current = node;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->key;
}


void findMinMaxAVL(NodeAVL *root)
{
    int min = findMinAVL(root);
    int max = findMaxAVL(root);
    std::cout << "Min: " << min << std::endl << "Max: " << max << std::endl;
}


void printBST(NodeBST *root)
{
    std::cout << "  In-order: ";
    inorderBST(root);
    std::cout << std::endl << "Post-order: ";
    postorderBST(root);
    std::cout << std::endl << " Pre-order: ";
    preorderBST(root);
    std::cout << std::endl;
}


void printAVL(NodeAVL *root)
{
    std::cout << "  In-order: ";
    inorderAVL(root);
    std::cout << std::endl << "Post-order: ";
    postorderAVL(root);
    std::cout << std::endl << " Pre-order: ";
    preorderAVL(root);
    std::cout << std::endl;
}
