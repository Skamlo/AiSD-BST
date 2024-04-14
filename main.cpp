#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "BST.h"
#include "AVL.h"
#include "menuFunctions.h"

#define NAN 0
#define AVL 1
#define BST 2

int treeType = NAN;


bool textValidation(std::string* numbers){
    std::string newNumbers;
    int lastIndex = -1;
    for(int i=0; i<numbers->size(); i++)
    {
        if((*numbers)[i] == ' ')
        {
            if(lastIndex != -1)
            {
                if(newNumbers[lastIndex] != ' ')
                {    newNumbers += ' ';
                    lastIndex += 1;
                }
            }
        }
        else if((*numbers)[i] >= '0' && (*numbers)[i] <= '9')
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


void convertNodes(std::vector<int>* nodes, std::string numbers)
{
    int currentNumber = 0;
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == ' ')
        {
            nodes->push_back(currentNumber);
            currentNumber = 0;
        }
        else if(numbers[i] >= '0' && numbers[i] <= '9')
        {
            currentNumber = currentNumber * 10 + (numbers[i] - '0');
        }
    }
    nodes->push_back(currentNumber);
}


int main(int argc, char* argv[])
{
    // loading tree type
    if(argc >= 3)
    {
        if(!std::strcmp(argv[1], "--tree") && !std::strcmp(argv[2], "AVL"))
            treeType = AVL;
        else if(!std::strcmp(argv[1], "--tree") && !std::strcmp(argv[2], "BST"))
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

    if(textValidation(&loadValues))
        convertNodes(&nodes, loadValues);
    else
        std::cout << "Incorrect input values" << std::endl;

    // creating the tree
    NodeBST *rootBST = new NodeBST();
    NodeAVL *rootAVL = new NodeAVL();
    if(treeType == BST)
        rootBST = createBST(nodes);
    else if(treeType == AVL)
        rootAVL = createAVL(nodes, 0, nodes.size()-1);

    // Menu
    std::string option;
    while (true)
    {
        std::cout << "\naction> ";
        std::getline(std::cin, option);
    
        if(option == "FindMinMax" || option == "findMinMax" || option == "findminmax")
        {
            if(treeType == BST)
                findMinMaxBST(rootBST);
            else if(treeType = AVL)
                // Nie działa (chuj wie o co chodzi)
                findMinMaxAVL(rootAVL);
        }
        else if(option == "Print" || option == "print")
        {
            if(treeType == BST)
                printBST(rootBST);
            else if(treeType == AVL)
                printAVL(rootAVL);
        }
        else if(option == "Delete" || option == "delete")
        {
            
        }
        else if(option == "Delete All" || option == "delete all")
        {
            
        }
        else if(option == "Rebalance" || option == "rebalance")
        {
            
        }
        else if(option == "Help" || option == "help")
        {
            std::cout << "Help         Show this message" << std::endl
                      << "Print        Print the tree usin In-order, Pre-order, Post-order" << std::endl
                      << "Delete       Delete elements of the tree" << std::endl
                      << "Delete All   Delete whole tree" << std::endl
                      << "Rebalance    Rebalance the tree" << std::endl
                      << "Exit         Exits the program (same as ctrl+D)" << std::endl;
        }
        else if(option == "Exit" || option == "exit")
        {
            break;
        }
        else
            std::cout << "This command does not exist." << std::endl;
    }

    return 0;
}
