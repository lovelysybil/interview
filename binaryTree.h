struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(int n=0):nvalue(n),right(NULL),left(NULL){}
};

void CreateBinaryTree(BinaryTreeNode* &root);
void DestoryBinaryTree(BinaryTreeNode* &root);

void PreOrder_rec(const BinaryTreeNode *root);
void MidOrder_rec(const BinaryTreeNode *root);
void PostOrder_rec(const BinaryTreeNode *root);
