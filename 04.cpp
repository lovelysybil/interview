#include "iostream"
using namespace std;

//替换字符串中的空格为%20

void ReplaceBlank(char *str, int len)
{
    if(str == NULL || len <= 0)
        return;

    int nNewLen = 0;
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == ' ')
            nNewLen += 2;
        nNewLen++;
    }

    if(len < nNewLen+1)
        return;

    char *p = str + strlen(str);
    char *q = str + nNewLen;

    while(p >= str)
    {
        if(*p == ' ')
        {
            strncpy(q-2, "02%", 3);
            q -= 3;
        }
        else
        {
            *q = *p;
            q--;
        }

        p--;
    }
}

int main()
{
    char str[100];
    memset(str, '\0', sizeof(str));

    strcpy(str, "");
    ReplaceBlank(str, 100);
    cout << str << endl;

    strcpy(str, " ");
    ReplaceBlank(str, 100);
    cout << str << endl;

    strcpy(str, "  ");
    ReplaceBlank(str, 100);
    cout << str << endl;

    strcpy(str, "we are family!!");
    ReplaceBlank(str, 100);
    cout << str << endl;

    strcpy(str, " 1 ");
    ReplaceBlank(str, 100);
    cout << str << endl;

    return 0;
}


