struct ListNode
{
    int nValue;
    ListNode *pNext;
    ListNode(int n =0):nValue(n),pNext(NULL){}
};

void CreateList(ListNode* &pHead);
void DestoryList(ListNode* &pHead);

void PrintListFromHead(ListNode*);
void PrintListFromTail(ListNode*);

