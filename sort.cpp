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

void puppleSort(int *arr, int len)
{
    if(NULL == arr || len <= 1)
        return;

    for(int i=0; i<len-1; i++)
    {
        for(int j=len-1; j>i; j--)
        {
            if(arr[j-1] > arr[j])
                swap(arr[j-1], arr[j]);
        }
    }
}

void insertSort(int *arr, int len)
{
    if(NULL == arr || len <= 1)
        return;

    for(int i=0; i<len; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j-1] > arr[j])
                swap(arr[j-1], arr[j]);
        }
    }
}

void combine(int *arr, int *arr1, int *arr2, int len, int len1, int len2)
{
    int *tmp = new int[len];
    memset(tmp, '\0', sizeof(int)*len);

    int i = 0, j = 0, k = 0;

    while(j < len1 && k < len2)
    {
        if(arr1[j] < arr2[k])
            tmp[i++] = arr1[j++];
        else
            tmp[i++] = arr2[k++];
    }

    while(j < len1)
        tmp[i++] = arr1[j++];

    while(k < len2)
        tmp[i++] = arr2[k++];

    memcpy(arr, tmp, sizeof(int)*len);
    delete []tmp;
}

void combineSort(int *arr, int len)
{
    if(NULL == arr || len <= 1)
        return;

    int mid = len>>1;

    combineSort(arr, mid);
    combineSort(arr+mid, len-mid);

    combine(arr, arr, arr+mid, len, mid, len-mid);
}

void shellSort(int *arr, int len)
{
    if(NULL == arr || len <= 1)
        return;

    for(int step=len/2; step>0; step/=2)//步长
    {
        for(int i=0; i<step; i++)//步长插入排序
        {
            for(int j=i+step; j<len; j+=step)
            {
                if(arr[j-step] > arr[j])
                {
                    int tmp = arr[j];
                    int k = j - step;
                    while(k >= 0 && arr[k] > tmp)
                    {
                        arr[k+step] = arr[k];
                        k -= step;
                    }
                    arr[k+step] = tmp;
                }
            }
        }
    }
}



int main()
{
    int arr[] = {3,1,4,2,5,7,0,9};
    int arr1[] = {0,1,2,3,4,5};
    int arr2[] = {5,4,3,2,1,0};
    int arr3[] = {0,0,2,2,1,10};
    int arr4[] = {0};

    /* quickSort(arr, 0, sizeof(arr)/sizeof(int)-1); */
    /* quickSort(arr1, 0, sizeof(arr1)/sizeof(int)-1); */
    /* quickSort(arr2, 0, sizeof(arr2)/sizeof(int)-1); */
    /* quickSort(arr3, 0, sizeof(arr3)/sizeof(int)-1); */
    /* quickSort(arr4, 0, sizeof(arr4)/sizeof(int)-1); */

    /* puppleSort(arr, sizeof(arr)/sizeof(int)); */
    /* puppleSort(arr1, sizeof(arr1)/sizeof(int)); */
    /* puppleSort(arr2, sizeof(arr2)/sizeof(int)); */
    /* puppleSort(arr3, sizeof(arr3)/sizeof(int)); */
    /* puppleSort(arr4, sizeof(arr4)/sizeof(int)); */

    /* insertSort(arr, sizeof(arr)/sizeof(int)); */
    /* insertSort(arr1, sizeof(arr1)/sizeof(int)); */
    /* insertSort(arr2, sizeof(arr2)/sizeof(int)); */
    /* insertSort(arr3, sizeof(arr3)/sizeof(int)); */
    /* insertSort(arr4, sizeof(arr4)/sizeof(int)); */

    /* combineSort(arr, sizeof(arr)/sizeof(int)); */
    /* combineSort(arr1, sizeof(arr1)/sizeof(int)); */
    /* combineSort(arr2, sizeof(arr2)/sizeof(int)); */
    /* combineSort(arr3, sizeof(arr3)/sizeof(int)); */
    /* combineSort(arr4, sizeof(arr4)/sizeof(int)); */

    shellSort(arr, sizeof(arr)/sizeof(int));
    shellSort(arr1, sizeof(arr1)/sizeof(int));
    shellSort(arr2, sizeof(arr2)/sizeof(int));
    shellSort(arr3, sizeof(arr3)/sizeof(int));
    shellSort(arr4, sizeof(arr4)/sizeof(int));

    for(int i=0; i<sizeof(arr)/sizeof(int); i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    for(int i=0; i<sizeof(arr1)/sizeof(int); i++)
        cout<<arr1[i]<<" ";
    cout<<endl;

    for(int i=0; i<sizeof(arr2)/sizeof(int); i++)
        cout<<arr2[i]<<" ";
    cout<<endl;

    for(int i=0; i<sizeof(arr3)/sizeof(int); i++)
        cout<<arr3[i]<<" ";
    cout<<endl;

    for(int i=0; i<sizeof(arr4)/sizeof(int); i++)
        cout<<arr4[i]<<" ";
    cout<<endl;
    return 0;
}




