#pragma once

#include "BST.h"
#include "AVL.h"

std::string stringToLowercase(std::string text);
bool textValidation(std::string *numbers);
int strToInt(std::string numberString);
void convertNodes(std::vector<int> *nodes, std::string numbers);
void printBST(NodeBST *root);
void printAVL(NodeAVL *root);
