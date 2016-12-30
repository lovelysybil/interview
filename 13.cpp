#include "iostream"
#include "list.h"
using namespace std;

void DeleteNode(ListNode **pListHead, ListNode *pToBeDel)
{
    if(!pListHead || !pToBeDel)
        return;

    if(pToBeDel->pNext != NULL)
    {
        ListNode *p = pToBeDel->pNext;
        pToBeDel->nValue = p->nValue;
        pToBeDel->pNext = p->pNext;
        delete p;
    }
    else if(*pListHead == pToBeDel)
    {
        delete pToBeDel;
        pToBeDel = NULL;
        *pListHead = NULL;
    }
    else
    {
        ListNode *p = *pListHead;

        while(p->pNext != NULL)
        {
            if(p->pNext == pToBeDel)
                break;

            p = p->pNext;
        }

        if(p->pNext == NULL)
            return;

        p->pNext = pToBeDel->pNext;
        delete pToBeDel;
        pToBeDel = NULL;
    }
}

int main()
{
    ListNode *pHead = NULL;
    CreateList(pHead);

    PrintListFromHead(pHead);

    DeleteNode(&pHead, pHead->pNext->pNext);

    PrintListFromHead(pHead);

    DestoryList(pHead);


    return 0;
}


