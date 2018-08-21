#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    int len = b.length(), count = 0;
    for(int i = 0; i < len; i++)
    {
        int p = lower_bound(a.begin(),a.end(),b[i]) - a.begin();
        if(p == a.end() -a.begin() || a[p] != b[i])
            count++;
        else
            a.erase(a.begin()+p);
    }
    if(count)
        printf("No %d\n",count);
    else
        printf("Yes %d\n",a.length());
}
