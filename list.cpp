#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "list.h"
using namespace std;

void CreateList(ListNode* &pHead)
{
    int n = 0;
    char szTmp[10];
    if(pHead == NULL)
    {
        fgets(szTmp, sizeof(szTmp), stdin);
        if(szTmp[0] == ' ')
            return;

        n = atoi(szTmp);
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

