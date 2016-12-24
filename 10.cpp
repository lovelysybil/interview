#include "iostream"
using namespace std;

int NumberOf1(int n)
{
    int count = 0;

    while(n)
    {
        count++;
        n = n&(n-1);
    }

    return count;
}

int main()
{
    int n = 0;
    cin >> n;
    cout << hex << n << endl;
    cout << dec << NumberOf1(n) << endl;

    return 0;
}
