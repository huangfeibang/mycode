#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<string> ans;
int main()
{
    string a;
    char ch;
    while(cin>>a)
    {
        ans.push_back(a);
        if ((ch = getchar()) == '\n')
            break;
    }
    for(int i = ans.size()-1;i>0;i--)
        cout<<ans[i]<<' ';
    cout<<ans[0]<<endl;
    return 0;
}

