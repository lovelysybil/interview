#include "iostream"
#include "binaryTree.h"

using namespace std;

void PrintBinaryTreeByLevelLR(BinaryTreeNode *root);

int main()
{
    BinaryTreeNode *root = NULL;
    CreateBinaryTree(root);

    PrintBinaryTreeByLevelLR(root);

    DestoryBinaryTree(root);

    return 0;
}
