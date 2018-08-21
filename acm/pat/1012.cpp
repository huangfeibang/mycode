#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int a, b, n, max = 0 ,sum1 = 0, f = 1, sum2 = 0, sum3 = 0, count = 0 ,count2 = 0;
    int f0  = 0,f1 = 0, f2 = 0,f3 = 0,f4 = 0;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> a;
        if(a % 10 == 0)
        {
             sum1 += a;
             f0 = 1;
        }
        if(a % 5 == 1)
        {
            sum2 += a*f;
            f = (f == -1?1:-1);
            f1 = 1;
        }
        if(a %5 == 2)
        {
             count2++;
             f2 = 1;
        }
        if(a %5 == 3)
        {
            sum3 += a;
            count++;
            f3 = 1;
        }
        if(a % 5 == 4)
        {
            if(a > max)
                max = a;
            f4 = 1;
        }

    }
    if(f0)
        cout<<sum1<<' ';
    else
        cout<<'N'<<' ';
    if(f1)
        cout<<sum2<<' ';
    else
        cout<<'N'<<' ';
    if(f2)
        cout<<count2<<' ';
    else
        cout<<'N'<<' ';
    if(f3)
        printf("%.1f ",sum3*1.0/count);
    else
        cout<<'N'<<' ';
    if(f4)
        cout<<max;
    else
        cout<<'N';
    return 0;
}
