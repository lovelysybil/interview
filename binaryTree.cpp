#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "binaryTree.h"
using namespace std;

void CreateBinaryTree(BinaryTreeNode* &root)
{
    if(NULL == root)
    {
        char szTmp[10];
        fgets(szTmp, sizeof(szTmp), stdin);

        if(szTmp[0] == ' ')
            return;

        root = new BinaryTreeNode(atoi(szTmp));
        CreateBinaryTree(root->left);
        CreateBinaryTree(root->right);
    }
}
void DestoryBinaryTree(BinaryTreeNode* &root)
{
    if(root == NULL)
        return;

    DestoryBinaryTree(root->left);
    DestoryBinaryTree(root->right);

    delete root;
    root = NULL;
}

void PreOrder_rec(const BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    cout<<root->nValue<<endl;
    PreOrder_rec(root->left);
    PreOrder_rec(root->right);
}

void MidOrder_rec(const BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    PreOrder_rec(root->left);
    cout<<root->nValue<<endl;
    PreOrder_rec(root->right);
}

void PostOrder_rec(const BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    PreOrder_rec(root->left);
    PreOrder_rec(root->right);
    cout<<root->nValue<<endl;
}
