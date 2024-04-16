#pragma once

#include "BST.h"
#include "AVL.h"

std::string stringToLowercase(std::string text);
bool textValidation(std::string *numbers);
int strToInt(std::string numberString);
void convertNodes(std::vector<int> *nodes, std::string numbers);
void findMinMaxBST(NodeBST *node);
void findMinMaxAVL(NodeAVL *node);
void printBST(NodeBST *root);
void printAVL(NodeAVL *root);
bool checkIfKeyExistBST(NodeBST* root, int key);
bool checkIfKeyExistAVL(NodeAVL* root, int key);
NodeBST* deleteNodeBST(NodeBST* root, int key);
NodeAVL* deleteNodeAVL(NodeAVL* root, int key);
