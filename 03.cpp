#include "iostream"
using namespace std;

//链表的相关
struct ListNode
{
    int nValue;
    ListNode *next;
};


//链表尾部添加一个结点
void AddToTail(ListNode **pHead, int value)
{
    ListNode *pTmp = new ListNode();
    pTmp->nValue = value;
    pTmp->next = NULL;

    if(*pHead == NULL)
        *pHead = pTmp;
    else
    {
        ListNode *pNode = *pHead;
        while(pNode->next != NULL)
            pNode = pNode->next;

        pNode->next = pTmp;
    }
}
