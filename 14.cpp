#include "iostream"
using namespace std;

void ReorderEvenOdd(int *pData, int len)
{
    if(pData == NULL || len <= 0)
        return;

    int *p = pData;
    int *q = pData + len - 1;

    while(1)
    {
        while((*p&0x1) != 0)
            p++;

        while((*q&0x1) == 0)
            q--;

        if(p >= q)
            break;

        int tmp = *p;
        *p = *q;
        *q = tmp;
    }
}

int main()
{
    int arr[] = {2,3,6,9,11};

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        cout << arr[i] << " ";
    cout << endl;

    ReorderEvenOdd(arr, sizeof(arr)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
