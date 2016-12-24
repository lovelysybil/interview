#include "iostream"
using namespace std;

//二叉树遍历

struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode *pLeft;
    BinaryTreeNode *pRight;

    BinaryTreeNode(int value):pLeft(NULL),pRight(NULL){
        nValue = value;
    }
};


void CreateBinaryTree(BinaryTreeNode* &pRoot)
{
    int nTmp = 0;
    cin >> nTmp;

    if(nTmp == -999)
        pRoot = NULL;
    else
    {
        pRoot = new BinaryTreeNode(nTmp);
        CreateBinaryTree(pRoot->pLeft);
        CreateBinaryTree(pRoot->pRight);
    }
}




