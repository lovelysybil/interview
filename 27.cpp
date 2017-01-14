#include "iostream"
#include "stack"
#include "binaryTree.h"

using namespace std;

BinaryTreeNode *ConvertToDlist(BinaryTreeNode *root)
{
    if(root == NULL)
        return NULL;

    stack<BinaryTreeNode*> stk;
    BinaryTreeNode *preNode = NULL;
    BinaryTreeNode *Node = NULL;

    while(1)
    {
        if(root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
        else
        {
            if(stk.size() == 0)
                break;
            else
            {
                root = stk.top();
                stk.pop();

                Node = root;
                root = root->right;

                if(Node)
                    Node->left = preNode;
                if(preNode)
                    preNode->right = Node;

                preNode = Node;
            }
        }
    }

    while(Node->left != NULL)
        Node = Node->left;

    return Node;
}

int main()
{
    BinaryTreeNode *root = NULL;
    CreateBinaryTree(root);

    root = ConvertToDlist(root);

    while(root->right != NULL)
    {
        cout<<root->nValue<<"<";
        root = root->right;
    }
    cout<<root->nValue<<endl;

    while(root->left != NULL)
    {
        cout<<root->nValue<<">";
        root = root->left;
    }
    cout<<root->nValue<<endl;

    return 0;
}
