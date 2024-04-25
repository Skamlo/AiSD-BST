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

bool textValidation(std::string *numbers) // Performs preprocessing data such as removing spaces
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
    for (int i = 0; i < numberString.length(); i++)
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
