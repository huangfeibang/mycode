#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> ans;
int main()
{
    int n,a;
    cin>>n>>a;
    ans.resize(n);
    a = a%n;
    for(int i = 0;i<n;i++)
        scanf("%d",&ans[(i+a)%n]);
    for(int i =0;i<n-1;i++)
        cout<<ans[i]<<' ';
    cout<<ans[n-1]<<endl;
    return 0;
}
