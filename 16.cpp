#include "iostream"
#include "list.h"
using namespace std;

ListNode *ConvertList(ListNode* &head)
{
    if(NULL == head)
        return NULL;

    ListNode *p, *q, *r;
    p = head;
    q = p->pNext;
    r = NULL;

    while(q != NULL)
    {
        r = q->pNext;
        q->pNext = p;
        p = q;
        q = r;
    }
    head->pNext = NULL;

    return p;
}

int main()
{
    ListNode *head = NULL;
    CreateList(head);

    head = ConvertList(head);
    PrintListFromHead(head);

    DestoryList(head);

    return 0;
}
