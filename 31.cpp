#include "iostream"
using namespace std;

int FindGreatestSumOfSubArray(int *pData, int nLen)
{
    if(pData == NULL || nLen <= 0)
        return 0;

    int sumMax = 0x80000000;
    int sum = 0;

    for(int i=0; i<nLen; i++)
    {
        if(sum >= 0)
            sum += pData[i];
        else
            sum = pData[i];

        if(sum > sumMax)
            sumMax = sum;
    }

    return sumMax;
}

int main()
{
    int len;
    cin>>len;

    int *arr = new int[len];
    for(int i=0; i<len; i++)
        cin>>arr[i];

    cout<<FindGreatestSumOfSubArray(arr, len)<<endl;

    delete []arr;

    return 0;
}
