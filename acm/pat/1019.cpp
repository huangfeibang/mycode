#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char number[1001], ans[1000];

    scanf("%s",number);
    int B, len, j = 0;
    len = strrlen(number);
    for(int i = 0;i<len;i++)
    {
        if((num[i]-'0')/B)
        {
            ans[j++] = (num[i]-'0')/B;
        }
        int x = (num[i]-'0')%B;
    }
    return 0;
}
