#include "iostream"
#include "list.h"
using namespace std;

void CreateList(ListNode* &pHead)
{
    int n = 0;
    if(pHead == NULL)
    {
        cin >> n;
        if(n == -999)
            return;
        pHead = new ListNode(n);
        CreateList(pHead->pNext);
    }
}

void DestoryList(ListNode* &pHead)
{
    if(pHead == NULL)
        return;

    ListNode *p = pHead;
    ListNode *q = NULL;
    while(p->pNext != NULL)
    {
        q = p;
        p = p->pNext;
        delete q;
    }
}

void PrintListFromHead(ListNode *pHead)
{
    while(pHead != NULL)
    {
        cout << pHead->nValue << endl;
        pHead = pHead->pNext;
    }
}

void PrintListFromTail(ListNode *pHead)
{
    if(pHead == NULL)
    {
        return;
    }

    PrintListFromTail(pHead->pNext);
    cout << pHead->nValue << endl;
}

