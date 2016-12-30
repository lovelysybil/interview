#include "iostream"
#include "string.h"
using namespace std;

int Increment(char *str, int len)
{
    if(len <= 0)
        return 1;

    if(str[len-1] < '9')
    {
        str[len-1] += 1;
        return 0;
    }
    else
    {
        str[len-1] = '0';
        return Increment(str, len-1);
    }

    return 0;
}

void PrintNumber(char *number)
{
    if(number == NULL)
        return;

    while(*number == '0')
        number++;

    cout<<number<<endl;
}

void PrintToMaxOfN(int n)
{
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number, n))
        PrintNumber(number);

    delete []number;
}

int main()
{
    int n;
    cin >> n;
    PrintToMaxOfN(n);

    return 0;
}
