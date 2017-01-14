#include "iostream"
using namespace std;

int FindNumIndex(int *pArr, int len, int num)
{
    if(NULL == pArr || len <= 0)
        return -1;

    int start = 0, end = len-1;
    int mid = 0;

    while(start <= end)
    {
        mid = (start+end) >> 1;

        if(pArr[mid] == num)
            return mid+1;
        else if(pArr[mid] < num)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int len = 0, num = 0;
    cout<<"len:";
    cin>>len;

    int *arr = new int[len];
    for(int i=0; i<len; i++)
        cin>>arr[i];

    cout<<"num:";
    cin>>num;

    cout<<FindNumIndex(arr, len, num)<<endl;

    delete []arr;

    return 0;
}
