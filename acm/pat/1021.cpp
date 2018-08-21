#include<iostream>
#include<cstdio>
using namespace std;
int a[10] = {0};
int main()
{
    char c;
    while(scanf("%c",&c))
    {
        if(c=='\n')
            break;
        a[c-48]++;
    }
    for(int i = 0;i<10;i++)
    {
        if(a[i])
            printf("%d:%d\n", i, a[i]);
    }
    return 0;
}
