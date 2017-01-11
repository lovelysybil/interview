struct BinaryTreeNode
{
    int nValue;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(int n=0):nValue(n),right(NULL),left(NULL){}
};

void CreateBinaryTree(BinaryTreeNode* &root);
void DestoryBinaryTree(BinaryTreeNode* &root);

void PreOrder_rec(const BinaryTreeNode *root);
void MidOrder_rec(const BinaryTreeNode *root);
void PostOrder_rec(const BinaryTreeNode *root);
void PreOrder_iter(BinaryTreeNode *root);
void MidOrder_iter(BinaryTreeNode *root);
void PostOrder_iter(BinaryTreeNode *root);
void LevelOrder(BinaryTreeNode *root);
