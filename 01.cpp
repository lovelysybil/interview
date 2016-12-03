#include "iostream"
using namespace std;

//赋值预算符函数
class CMyString
{
public:
    CMyString(char *pData = NULL);
    CMyString(const CMyString &str);
    ~CMyString(void);

    CMyString& operator =(const CMyString &str);

private:
    char *m_pData;
};

//普通版本
CMyString& CMyString::operator =(const CMyString &str)
{
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = NULL;

    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

//高级版本
CMyString& CMyString::operator =(const CMyString &str)
{
    if(this != &str)
    {
        CMyString strTmp(str);

        //对象中指针替换
        char *pTmp = strTmp.m_pData;
        strTmp.m_pData = m_pData;
        m_pData = pTmp;
    }

    return *this;
}
