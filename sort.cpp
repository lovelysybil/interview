#include "iostream"
using namespace std;

void quickSort(int* arr, int start, int end)
{
    if(start >= end)
        return;

    int mid = arr[end];
    int midIndex = 0;
    int *p = arr + start;
    int *q = arr + end - 1;

    while(1)
    {
        while(*p < mid)
            p++;

        while(*q >= mid)
            q--;

        if(p >= q)
            break;
        else
        {
            int tmp = *p;
            *p = *q;
            *q = tmp;
        }
    }
    int tmp = *p;
    *p = arr[end];
    arr[end] = tmp;
    midIndex = p - arr;

    quickSort(arr, start, midIndex-1);
    quickSort(arr, midIndex+1, end);
}

int main()
{
    int arr[] = {3,1,2,5,7,4,9};
    int arr1[] = {0,1,2,3,4,5};
    int arr2[] = {5,4,3,2,1,0};

    quickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    quickSort(arr1, 0, sizeof(arr1)/sizeof(int)-1);

    for(int i=0; i<sizeof(arr1)/sizeof(int); i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    quickSort(arr2, 0, sizeof(arr2)/sizeof(int)-1);

    for(int i=0; i<sizeof(arr2)/sizeof(int); i++)
        cout<<arr2[i]<<" ";
    cout<<endl;
    return 0;
}




