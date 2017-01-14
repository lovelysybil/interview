#include "iostream"
#include "vector"
#include "algorithm"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

class DynamicArray
{
public:
    void Insert(int n)
    {
        if(((max.size()+min.size()) & 1) == 0)
        {
            //偶数个 插入最小堆(右半边)
            if(max.size() > 0 && n < max[0])
            {
                max.push_back(n);
                push_heap(max.begin(), max.end(), less<int>());

                n = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }

            min.push_back(n);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else
        {
            //奇数个 右半边较大 插入最大堆(左半边)
            if(min.size() > 0 && n > min[0])
            {
                min.push_back(n);
                push_heap(min.begin(), min.end(), greater<int>());

                n = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }

            max.push_back(n);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    {
        int size = max.size() + min.size();
        if(size == 0)
            return 0x80000000;
        if((size & 1) == 1)
            return min[0];
        else
            return (min[0]+max[0])/2.0;
    }

private:
    vector<int> max;
    vector<int> min;
};

int main()
{
    DynamicArray array;
    int n;
    char sz[10];
    while(1)
    {
        fgets(sz, sizeof(sz), stdin);
        if(sz[0] == ' ')
            break;

        n = atoi(sz);
        array.Insert(n);
    }

    cout << array.GetMedian() << endl;

    return 0;
}
