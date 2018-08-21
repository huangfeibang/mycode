#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> num;
vector<int> x;
vector<int> ans;
int main()
{
    int a, K;
    cin >>K;
    while(K)
    {
        scanf("%d",&a);
        x.push_back(a);
        sort(num.begin(),num.end());
        int p = lower_bound(num.begin(),num.end(),a) - num.begin();
        if(p == num.size() || a!=num[p])
        {

        }
        else
        {
            K--;
            continue;
        }
        while(a != 1)
        {
            if(a%2 == 0)
                a /= 2;
            else
                a = (3*a +1)/2;
            sort(num.begin(),num.end());
            p = lower_bound(num.begin(),num.end(),a) - num.begin();
            if(p == num.size() || a!=num[p])
                num.push_back(a);
        }
        K--;
    }
    sort(num.begin(),num.end());
    for(int i = 0;i<x.size();i++)
    {
        int p = lower_bound(num.begin(),num.end(),x[i]) - num.begin();
        if(p == num.size() || x[i]!=num[p])
        {
             ans.push_back(x[i]);
        }
    }
    sort(ans.begin(), ans.end(),greater<int>());
    int i;
    for(i = 0;i<ans.size()-1;i++)
    {
            cout<<ans[i]<<' ';
    }
    cout<<ans[i]<<endl;
    return 0;
}
