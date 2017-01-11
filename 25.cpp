#include "iostream"
#include "vector"
#include "binaryTree.h"
using namespace std;

void FindPath(BinaryTreeNode *root, int sum, vector<int> &path)
{
    if(root == NULL)
        return;

    path.push_back(root->nValue);

    if(root->left == NULL && root->right == NULL)
    {
        if(root->nValue == sum)
        {
            vector<int>::iterator iter= path.begin();
            for(; iter!=path.end(); iter++)
                cout<<*iter<<"->";
            cout<<endl;
        }
    }

    if(root->left)
        FindPath(root->left, sum-root->nValue, path);

    if(root->right)
        FindPath(root->right, sum-root->nValue, path);

    path.pop_back();
}

int main()
{
    BinaryTreeNode *root = NULL;
    int sum = 0;
    vector<int> path;
    CreateBinaryTree(root);

    cout<<"sum:";
    cin>>sum;
    FindPath(root, sum, path);

    DestoryBinaryTree(root);

    return 0;
}
