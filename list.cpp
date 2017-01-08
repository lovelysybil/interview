#include "iostream"
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

ListNode *FindTailKNode(ListNode *head, int k)
{
    if(head == NULL || k < 0)
        return NULL;

    ListNode *p = head;
    ListNode *q = p;

    for(int i=0; i<k; i++)
    {
        p = p->pNext;

        if(p == NULL)
            return NULL;
    }

    while(p->pNext != NULL)
    {
        p = p->pNext;
        q = q->pNext;
    }

    return q;
}

int main()
{
    ListNode *head = NULL;
    CreateList(head);

    ListNode *tmp = NULL;
    for(int i=0; i<5 ;i++)
    {
        if((tmp = FindTailKNode(head, i)) != NULL)
        {
            cout<<tmp->nValue<<endl;
        }
        else
            cout<<"out range"<<endl;
    }

    DestoryList(head);

    return 0;
}

