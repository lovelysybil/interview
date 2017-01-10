#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "binaryTree.h"
#include "stack"
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

    MidOrder_rec(root->left);
    cout<<root->nValue<<endl;
    MidOrder_rec(root->right);
}

void PostOrder_rec(const BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    PostOrder_rec(root->left);
    PostOrder_rec(root->right);
    cout<<root->nValue<<endl;
}

void PreOrder_iter(BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    BinaryTreeNode *p = root;
    stack<BinaryTreeNode*> stk;
    while(1)
    {
        if(p != NULL)
        {
            cout<<p->nValue<<endl;
            if(p->right != NULL)
                stk.push(p->right);
            p = p->left;
        }
        else if(stk.size() != 0)
        {
            p = stk.top();
            stk.pop();
        }
        else
            break;
    }
}

void MidOrder_iter(BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    BinaryTreeNode *p = root;
    stack<BinaryTreeNode*> stk;
    while(1)
    {
        if(p != NULL)
        {
            stk.push(p);
            p = p->left;
        }
        else if(stk.size() != 0)
        {
            p = stk.top();
            stk.pop();
            cout<<p->nValue<<endl;
            p = p->right;
        }
        else
            break;
    }
}

void PostOrder_iter(BinaryTreeNode *root)
{



}

int main()
{
    BinaryTreeNode *root = NULL;
    CreateBinaryTree(root);

    PreOrder_rec(root);
    cout<<"-----"<<endl;
    PreOrder_iter(root);
    cout<<"-----"<<endl;
    MidOrder_rec(root);
    cout<<"-----"<<endl;
    MidOrder_iter(root);
    cout<<"-----"<<endl;

    DestoryBinaryTree(root);

    return 0;
}
