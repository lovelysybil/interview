#include "iostream"
#include "list.h"
using namespace std;

ListNode *MergeList(ListNode* &fst, ListNode* &sec)
{
    if(fst == NULL)
        return sec;
    if(sec == NULL)
        return fst;

    ListNode *rst = NULL;

    if(fst->nValue < sec->nValue)
    {
        rst = fst;
        rst->pNext = MergeList(fst->pNext, sec);
    }
    else
    {
        rst = sec;
        rst->pNext = MergeList(fst, sec->pNext);
    }

    return rst;
}

int main()
{
    ListNode *fst = NULL;
    ListNode *sec = NULL;

    cout<<"输入递增排序"<<endl;
    CreateList(fst);
    CreateList(sec);

    ListNode *tmp = MergeList(fst, sec);
    PrintListFromHead(tmp);

    DestoryList(tmp);

    return 0;
}
