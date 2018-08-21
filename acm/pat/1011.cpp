#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long a, b, c, T;
    cin>>T;
    for(int i = 1;i<=T;i++)
    {
        printf("Case #%d: ",i);
        cin>>a>>b>>c;
        if(a+b>c)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}
