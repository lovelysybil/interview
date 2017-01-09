#include "iostream"
#include "list.h"
using namespace std;

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
    ListNode *tmp = NULL;
    CreateList(head); 

    for(int i=0; i<5; i++)
    {
        if((tmp = FindTailKNode(head, i)) == NULL)
            cout<<"out of range"<<endl;
        else
            cout<<tmp->nValue<<endl;
    }

    DestoryList(head); 
    return 0;
}
