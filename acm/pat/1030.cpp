#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> list;
int main()
{
    long long a, N,p;
    int max = 0;
    cin>>N>>p;
    for(int i = 0;i<N;i++)
    {
        cin>>a;
        list.push_back(a);
    }
    sort(list.begin(),list.end());
    for(int i =0;i<list.size();i++)
    {
        for(int j = list.size()-1;j>i;j--)
        {
            if(list[j] <= list[i]*p)
            {
                if(j-i+1>=max)
                    max = j-i+1;
                break;
            }
        }
    }
    cout<<max;
    return 0;
}
