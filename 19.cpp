#include "iostream"
#include "binaryTree.h"
using namespace std;

void MirrorTree(BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    BinaryTreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    MirrorTree(root->left);
    MirrorTree(root->right);
}

int main()
{
    BinaryTreeNode *root = NULL;
    CreateBinaryTree(root);

    MirrorTree(root);
    PreOrder_rec(root); 
    cout<<"-----"<<endl;
    MidOrder_rec(root); 

    DestoryBinaryTree(root);
}

