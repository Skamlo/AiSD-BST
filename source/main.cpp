#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "BST.h"
#include "AVL.h"
#include "menuFunctions.h"

#define PLACEHOLDER 0
#define AVL 1
#define BST 2

int treeType = PLACEHOLDER;
bool isValidInputValues = true;

int main(int argc, char *argv[])
{
    // loading tree type
    if (argc >= 3)
    {
        if ((!std::strcmp(argv[1], "--tree") || !std::strcmp(argv[1], "-t")) && !std::strcmp(argv[2], "AVL"))
            treeType = AVL;
        else if ((!std::strcmp(argv[1], "--tree") || !std::strcmp(argv[1], "-t")) && !std::strcmp(argv[2], "BST"))
            treeType = BST;
        else
        {
            std::cout << "You incorrect specify the tree type.\n";
            return 1;
        }
    }
    else
    {
        std::cout << "You did not specify the tree type." << std::endl;
        return 1;
    }

    // loading values
    std::string loadValues;
    std::vector<int> nodes;

    std::cout << "Enter values: ";
    std::getline(std::cin, loadValues);

    if (textValidation(&loadValues))
    {
        convertNodes(&nodes, loadValues);
    }
    else
    {
        std::cout << "Incorrect input values\n" << std::endl;
        isValidInputValues = false;
    }

    // creating the tree
    NodeBST *rootBST = new NodeBST();
    NodeAVL *rootAVL = new NodeAVL();
    if (treeType == BST)
        rootBST = createBST(nodes);
    else if (treeType == AVL)
        rootAVL = createAVL(nodes, 0, nodes.size() - 1);

    // Menu
    std::string option;
    while (isValidInputValues)
    {
        std::cout << "\naction> ";
        std::getline(std::cin, option);
        option = stringToLowercase(option);
        if (option == "findminmax")
        {
            if (treeType == BST)
                findMinMaxBST(rootBST);
            else if (treeType == AVL)
                findMinMaxAVL(rootAVL);
        }
        else if (option == "print")
        {
            if (treeType == BST)
                printBST(rootBST);
            else if (treeType == AVL)
                printAVL(rootAVL);
        }
        else if (option == "delete")
        {
            std::cout << "Enter the node key you want to delete: ";
            std::string keyString;
            std::getline(std::cin, keyString);
            int key = strToInt(keyString);

            if (treeType == BST)
            {
                if (checkIfKeyExistBST(rootBST, key))
                {
                    deleteNodeBST(rootBST, key);
                    std::cout << "Key " << key << " was successfully deleted.\n";
                }
                else
                    std::cout << "Node with key " << key << " does not exist.\n";
            }
            else if (treeType == AVL)
            {
                if (checkIfKeyExistAVL(rootAVL, key))
                {
                    deleteNodeAVL(rootAVL, key);
                    std::cout << "Key " << key << " was successfully deleted.\n";
                }
                else
                    std::cout << "Node with key " << key << " does not exist.\n";
            }
        }
        else if (option == "delete all" || option == "deleteall")
        {
            if (treeType == BST)
            {
                delete rootBST;
                std::cout << "BST tree was sucessfuly deleted.\n";
            }
            else if (treeType == AVL)
            {
                delete rootAVL;
                std::cout << "AVL tree was sucessfuly deleted.\n";
            }
            break;
        }
        else if (option == "rebalance")
        {
            if (treeType == BST)
            {
                rootBST = balanceBST(rootBST);
                std::cout << "BST tree was sucessfuly rebalanced.\n";
            }
            else if (treeType == AVL)
            {
                std::cout << "This command does not exist." << std::endl;
            }
        }
        else if (option == "help")
        {
            std::cout << "Help         Show this message" << std::endl
                      << "Print        Print the tree usin In-order, Pre-order, Post-order" << std::endl
                      << "FindMinMax   Find min and max values in tree" << std::endl
                      << "Delete       Delete elements of the tree" << std::endl
                      << "Delete All   Delete whole tree" << std::endl;
            if (treeType == BST)
                std::cout << "Rebalance    Rebalance the tree" << std::endl;
            std::cout << "Exit         Exits the program" << std::endl;
        }
        else if (option == "exit")
        {
            break;
        }
        else
            std::cout << "This command does not exist." << std::endl;
    }

    return 0;
}
