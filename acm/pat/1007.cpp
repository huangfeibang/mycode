#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int vis[10005];
vector<int> prime;
int main()
{
    int n, m ,count = 0;
    cin>>n;
    m = sqrt(n+0.5);
    memset(vis, 0, sizeof(vis));
    for(int i = 2;i<=m;i++)
        for(int j = i*i;j<=n;j+=i)
            vis[j] = 1;
    for(int i = 2;i<=n;i++)
        if(vis[i] == 0)
            prime.push_back(i);
    for(int i = 0;i<prime.size();i++)
        if(prime[i+1] - prime[i] == 2)
            count++;
    cout << count << endl;
    return 0;
}
