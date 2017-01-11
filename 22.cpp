#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stack"
using namespace std;

bool CheckStackInOutOrder(char *InOrder, char *OutOrder)
{
    if(InOrder == NULL || OutOrder == NULL)
        return false;

    if(strlen(InOrder) != strlen(OutOrder))
        return false;

    stack<char> stk;

    int len = strlen(InOrder);

    int i=0,j=0;

    while(i<len && j<len)
    {
        if(stk.size() == 0 || stk.top() != OutOrder[j])
        {
            stk.push(InOrder[i++]);
        }

        if(stk.top() == OutOrder[j])
        {
            stk.pop();
            j++;
        }
    }

    return i==len && j==len && stk.empty();
}

int main()
{
    char str1[20];
    char str2[20];

    memset(str1, '\0', sizeof(str1));
    memset(str2, '\0', sizeof(str2));

    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    cout<<CheckStackInOutOrder(str1, str2)<<endl;

    return 0;
}

