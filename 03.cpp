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

//链表删除某结点
void RemoveNode(ListNode **pHead, int value)
{
    if(pHead == NULL || *pHead == NULL)
        return;

    ListNode *pToBeDeleted = NULL;
    if((*pHead)->nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;
    }
    else
    {
        ListNode *pNode = *pHead;
        while(pNode->next != NULL && pNode->next->nValue != value)
            pNode = pNode->next;

        if(pNode->next != NULL && pNode->next->nValue == value)
        {
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }
    }

    if(pToBeDeleted != NULL)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}
