#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int N, ff = 0;
    char a[19];
    int b[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8, 4, 2, 0};
    char c[] = {'1','0','X','9','8','7','6','5','4','3','2'};
    cin>>N;
    while(N)
    {
        int f = 0, ans = 0;
        scanf("%s",a);
        for(int i = 0 ;i<18;i++)
        {
             if(i<17 && !(a[i] >= '0' && a[i] <= '9'))
             {
                   f = 1;ff = 1;
                   break;
             }
             ans += (a[i]-48)*b[i];
        }
        ans %= 11;
        if(c[ans] != a[17])
        {
             f = 1;
             ff = 1;
        }

        if(f)
            printf("%s\n",a);
        N--;
    }
    if(ff == 0)
        printf("All passed");
    return 0;
}
