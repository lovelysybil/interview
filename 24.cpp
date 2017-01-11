#include "iostream"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

bool VerifySquenceOfBST(int *arr, int len)
{
    if(NULL == arr)
        return false;

    if(len <= 1)
        return true;

    int mid = arr[len-1];
    int i = len-2;

    for(; i>=0; i--)
    {
        if(arr[i] < mid)
            break;
    }

    for(int j=i; j>=0; j--)
    {
        if(arr[j] > mid)
            return false;
    }

    return VerifySquenceOfBST(arr, i+1) && VerifySquenceOfBST(arr+i+1, len-i-2);
}

int main()
{
    int arr[10] = {0};
    int len = 0;

    cin>>len;
    for(int i=0; i<len; i++)
        cin>>arr[i];

    cout<<VerifySquenceOfBST(arr, len)<<endl;

    return 0;
}
