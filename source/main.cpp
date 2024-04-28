#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "BST.h"
#include "AVL.h"
#include "menuFunctions.h"
#include <unistd.h>

#include <fstream>
#include <chrono>

#define PLACEHOLDER 0
#define AVL 1
#define BST 2

int treeType = PLACEHOLDER;
bool isValidInputValues = true;

int main(int argc, char *argv[])
{
    // Handle file with benchmark result
    std::ofstream outputFile{"output.csv", std::ios_base::app};

    if (!outputFile.is_open())
    {
        std::cout << "Nie mozna otworzyc pliku.\n";
        return 1;
    }
    // Loading tree type
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

    // Loading values
    std::string loadValues;
    std::vector<int> nodes;
    bool inputFromFile = !isatty(fileno(stdin)); // if program reads from file some elements of menu are not printed
    if (!inputFromFile)
    {
        std::cout << "Enter values: ";
    }
    std::getline(std::cin, loadValues);

    if (textValidation(&loadValues))
    {
        convertNodes(&nodes, loadValues);
    }
    else
    {
        std::cout << "Incorrect input values\n"
                  << std::endl;
        isValidInputValues = false;
    }

    // Creating the tree

    NodeBST *rootBST = new NodeBST();
    NodeAVL *rootAVL = new NodeAVL();
    if (treeType == BST)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        rootBST = createBST(nodes);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto measureTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        outputFile << measureTime.count() << " creatingBST " << nodes.size() << std::endl;
    }
    else if (treeType == AVL)
    {
        auto startTime = std::chrono::high_resolution_clock::now();
        std::sort(nodes.begin(), nodes.end());
        rootAVL = createAVL(nodes, 0, nodes.size() - 1);
        auto endTime = std::chrono::high_resolution_clock::now();
        auto measureTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
        outputFile << measureTime.count() << " creatingAVL " << nodes.size() << std::endl;
    }
    // Menu
    std::string option;
    while (isValidInputValues)
    {
        if (!inputFromFile)
            std::cout << "\naction> ";

        if (inputFromFile)
            std::cout << "\n";

        std::getline(std::cin, option);
        option = stringToLowercase(option);

        // Parameters handling
        if (option == "findminmax")
        {
            auto startTime = std::chrono::high_resolution_clock::now();
            if (treeType == BST)
                findMinMaxBST(rootBST);
            else if (treeType == AVL)
                findMinMaxAVL(rootAVL);
            auto endTime = std::chrono::high_resolution_clock::now();
            auto measureTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            outputFile << measureTime.count() << " findminmax " << nodes.size() << std::endl;
        }
        else if (option == "print")
        {
            auto startTime = std::chrono::high_resolution_clock::now();
            if (treeType == BST)
                printBST(rootBST);
            else if (treeType == AVL)
                printAVL(rootAVL);
            auto endTime = std::chrono::high_resolution_clock::now();
            auto measureTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            outputFile << measureTime.count() << " printing " << nodes.size() << std::endl;
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
            auto startTime = std::chrono::high_resolution_clock::now();
            if (treeType == BST)
            {
                rootBST = balanceBST(rootBST);
                std::cout << "BST tree was sucessfuly rebalanced.\n";
            }
            else if (treeType == AVL)
            {
                std::cout << "This command does not exist." << std::endl;
            }
            auto endTime = std::chrono::high_resolution_clock::now();
            auto measureTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            outputFile << measureTime.count() << " rebalance " << nodes.size() << std::endl;
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
            outputFile.close();
            break;
        }
        else
            std::cout << "This command does not exist." << std::endl;
    }
    return 0;
}
