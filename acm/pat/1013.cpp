#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int vis[200005];
vector<int> prime;
int main()
{
    int n = 200000, m ,count = 0, M ,N;
    cin>>M>>N;
    m = sqrt(n+0.5);
    memset(vis, 0, sizeof(vis));
    for(int i = 2;i<=m;i++)
        for(int j = i*i;j<=n;j+=i)
            vis[j] = 1;
    for(int i = 2;i<=200000;i++)
        if(vis[i] == 0)
            prime.push_back(i);
    for(int i = M-1;i<=N-1;i++)
    {
        count++;
        if(count%10 == 0|| i == N-1)
            cout<<prime[i]<<endl;
        else
            cout<<prime[i]<<' ';
    }
    return 0;
}
