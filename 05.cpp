#include "iostream"
#include "stack"
using namespace std;

//从尾到头打印链表

struct ListNode
{
    int nValue;
    ListNode *pNext;
};

//使用栈
void PrintFromTail(ListNode *pHead)
{
    stack<ListNode *> nodes;
    ListNode *pTmp = NULL;

    while(pHead != NULL)
    {
        nodes.push(pHead);
        pHead = pHead->pNext;
    }

    while(nodes.size() > 0)
    {
        pTmp = nodes.top();
        nodes.pop();
        cout << pTmp->nValue << " ";
    }

    cout << endl;
}

//使用递归
void PrintFromTail_Recursively(ListNode *pHead)
{
    if(pHead == NULL)
        return;

    PrintFromTail(pHead->pNext);
    cout << pHead->nValue << " ";
}



