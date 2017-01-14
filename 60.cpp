#include "iostream"
#include "binaryTree.h"

using namespace std;

void PrintBinaryTreeByLevel(BinaryTreeNode *root);

int main()
{

    BinaryTreeNode *root = NULL;
    CreateBinaryTree(root);

    PrintBinaryTreeByLevel(root);

    DestoryBinaryTree(root);

    return 0;
}
