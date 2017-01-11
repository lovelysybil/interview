#include "iostream"
#include "binaryTree.h"
using namespace std;

bool DoesTree1HasTree2(BinaryTreeNode *tree1, BinaryTreeNode *tree2);

bool HasSubTree(BinaryTreeNode *fth, BinaryTreeNode *son)
{
    bool result = false;

    if(fth != NULL && son != NULL)
    {
        if(fth->nValue == son->nValue)
            result = DoesTree1HasTree2(fth, son);

        if(!result)
            result = HasSubTree(fth->left, son);

        if(!result)
            result = HasSubTree(fth->right, son);
    }

    return result;
}

bool DoesTree1HasTree2(BinaryTreeNode *tree1, BinaryTreeNode *tree2)
{
    if(tree2 == NULL)
        return true;
    if(tree1 == NULL)
        return false;

    if(tree1->nValue == tree2->nValue)
        return DoesTree1HasTree2(tree1->left, tree2->left) && DoesTree1HasTree2(tree1->right, tree2->right);
    else
        return false;
}

int main()
{
    BinaryTreeNode *root1, *root2;
    root1 = root2 = NULL;
    cout<<"first:"<<endl;
    CreateBinaryTree(root1);

    cout<<"Second:"<<endl;
    CreateBinaryTree(root2);

    cout<<HasSubTree(root1, root2)<<endl;

    DestoryBinaryTree(root1);
    DestoryBinaryTree(root2);

    return 0;
}

