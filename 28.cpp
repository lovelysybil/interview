#include "iostream"
using namespace std;

void Permutation(char *pStr, char *pCur)
{
    if(pStr == NULL)
        return;

    if(*pCur == '\0')
    {
        cout<<pStr<<endl;
        return;
    }

    char *pConvert = pCur;
    char tmp;
    for(; *pConvert!='\0'; pConvert++)
    {
        tmp = *pCur;
        *pCur = *pConvert;
        *pConvert = tmp;

        Permutation(pStr, pCur+1);

        tmp = *pCur;
        *pCur = *pConvert;
        *pConvert = tmp;
    }
}

int main()
{
    char szTmp[10];
    cin>>szTmp;

    Permutation(szTmp, szTmp);
    
    return 0;
}
