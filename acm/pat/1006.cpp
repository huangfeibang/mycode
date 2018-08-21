#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, a, num;
    char s[2] = {'S','B'};
    cin >> n;
    num = n<10?1:n<100?2:n<1000?3:4;
    while(num)
    {
        a = n/(int)(pow(10,num-1)+0.5)%10;
        if(num != 1)
            for(int i =1;i<=a;i++)
                cout<<s[num-2];
        else
            for(int i =1;i<=a;i++)
                cout<<i;
        num--;
    }
    return 0;
}
