#include "iostream"
#include "vector"
#include "algorithm"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

//函数说明：
//make_heap将[start, end)范围进行堆排序，默认使用less<int>, 最大元素放在第一个(最大堆)。最小堆使用greater<int>。
//pop_heap将front（即第一个最大元素）移动到end的前部，同时将剩下的元素重新构造成(堆排序)一个新的heap。
//push_heap对刚插入的（尾部）元素做堆排序。
//sort_heap将一个堆做排序,最终成为一个有序的系列，可以看到sort_heap时，必须先是一个堆（两个特性：1、最大元素在第一个 2、添加或者删除元素以对数时间），因此必须先做一次make_heap.

int main()
{
    vector<int> array;
    int n;
    char sz[10];

    while(1)
    {
        fgets(sz, sizeof(sz), stdin);
        if(sz[0] == ' ')
            break;

        n = atoi(sz);
        array.push_back(n);
    }

    //创建最大堆
    make_heap(array.begin(), array.end(), less<int>());
    cout << "initial max heap: " << array.front() << endl;

    //弹出堆
    pop_heap(array.begin(), array.end(), less<int>());
    array.pop_back();
    cout << "max heap after pop: " << array.front() << endl;

    //插入堆
    array.push_back(99);
    push_heap(array.begin(), array.end(), less<int>());
    cout << "max heap after push: " << array.front() << endl;

    //排序 由小到大
    sort_heap(array.begin(), array.end());
    cout << "final sorted range: ";
    for (unsigned i=0; i<array.size(); i++) 
        cout << array[i] << " ";
    cout<<endl;

    //创建最小堆
    make_heap(array.begin(), array.end(), greater<int>());
    cout << "initial min heap: " << array.front() << endl;

    //弹出堆
    pop_heap(array.begin(), array.end(), greater<int>());
    array.pop_back();
    cout << "min heap after pop: " << array.front() << endl;

    //插入堆
    array.push_back(-100);
    push_heap(array.begin(), array.end(), greater<int>());
    cout << "min heap after push: " << array.front() << endl;

    //排序 由大到小
    sort_heap(array.begin(), array.end(), greater<int>());
    cout << "final sorted range: ";
    for (unsigned i=0; i<array.size(); i++) 
        cout << array[i] << " ";
    cout<<endl;

    return 0;
}

