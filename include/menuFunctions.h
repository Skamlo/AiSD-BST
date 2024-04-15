#pragma once

#include "BST.h"
#include "AVL.h"

std::string stringToLowercase(std::string text);
void findMinMaxBST(NodeBST *node);
void findMinMaxAVL(NodeAVL *node);
void printBST(NodeBST *root);
void printAVL(NodeAVL *root);