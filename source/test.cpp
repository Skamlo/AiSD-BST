#include <iostream>
#include <vector>
#include "AVL.h"

int main()
{
    std::vector<int> arr = {5, 8, 4, 9, 3, 2};
    int n = arr.size();

    NodeAVL *root = new NodeAVL();
    root = createAVL(&arr, 0, n-1);

    std::cout << "Inorder traversal of the AVL: ";
    inorderAVL(root);

    return 0;
}
