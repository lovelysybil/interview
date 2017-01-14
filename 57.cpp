#include "iostream"
#include "list.h"

using namespace std;

ListNode *DeleteDuplication(ListNode *root)
{
    if(NULL == root)
        return NULL;

    ListNode *p = root, *q = root->pNext;
    ListNode *tmp = NULL;

    while(q != NULL)
    {
        if(p->nValue != q->nValue)
        {
            p->pNext = q;
            p = q;
            q = q->pNext;
        }
        else
        {
            tmp = q;
            q = q->pNext;
            delete tmp;
            tmp = NULL;
        }
    }

    p->pNext = q;

    return root;
}

int main()
{
    ListNode *head = NULL;
    CreateList(head);

    DeleteDuplication(head);
    PrintListFromHead(head);

    DestoryList(head);
    return 0;
}
