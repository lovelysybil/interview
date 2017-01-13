#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "binaryTree.h"
#include "stack"
#include "queue"
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
        else 
        {
            if(stk.size() == 0)
                break;

            p = stk.top();
            stk.pop();
        }
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
        else
        {
            if(stk.size() == 0)
                break;

            p = stk.top();
            stk.pop();
            cout<<p->nValue<<endl;
            p = p->right;
        }
    }
}

void PostOrder_iter(BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    BinaryTreeNode *p = root;

    stack<BinaryTreeNode*> stk;
    stack<int> stk_sign;
    while(1)
    {
        if(p != NULL)
        {
            stk.push(p);
            stk_sign.push(0);
            p = p->left;
        }
        else
        {
            if(stk.size() == 0)
                break;

            p = stk.top();

            if(!stk_sign.top())
            {
                p = p->right;

                stk_sign.pop();
                stk_sign.push(1);
            }
            else
            {
                cout<<p->nValue<<endl;
                stk.pop();
                stk_sign.pop();
                p = NULL;
            }
        }
    }
}

void LevelOrder(BinaryTreeNode *root)
{
    if(NULL == root)
        return;

    queue<BinaryTreeNode*> que;
    que.push(root);

    while(!que.empty())
    {
        root = que.front();
        que.pop();
        
        cout<<root->nValue<<endl;

        if(root->left)
            que.push(root->left);
        
        if(root->right)
            que.push(root->right);
    }
}
