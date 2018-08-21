#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a1 ,b1 ,c1;
    long long sum1, sum2, ans;
    scanf("%d.%d.%d",&a1,&b1,&c1);
    sum1 = 17*29*a1+ 29*b1+c1;
    scanf("%d.%d.%d",&a1,&b1,&c1);
    sum2 = 17*29*a1+ 29*b1+c1;
    ans = sum2 - sum1;
    if(ans>=0)
        printf("%lld.%lld.%lld\n",ans/(17*29), (ans%(17*29))/29,ans%29);
    else
    {
        ans = ans*(-1);
        printf("-%lld.%lld.%lld\n",ans/(17*29), (ans%(17*29))/29,ans%29);
    }
    return 0;
}
