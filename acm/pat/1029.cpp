#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
vector<char> ans;
int main()
{

    char c, a[81], b[81];
    scanf("%s%s",a,b);
    int k = 0, lena;
    lena = strlen(a);
    for(int i = 0;i<lena;i++)
    {
        int f = 0;
        if(a[i] != b[k])
        {
            if(a[i]>='a'&&a[i]<='z')
                a[i] -= 32;
            for(int j = 0;j<ans.size();j++)
            {
                if(ans[j] == a[i])
                {
                    f = 1;
                    break;
                }
            }
            if(!f)
                ans.push_back(a[i]);
        }
        else
            k++;
    }
    for(int i = 0;i<ans.size();i++)
        cout<<ans[i];
    return 0;
}
