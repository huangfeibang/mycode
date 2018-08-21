#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> aa;
int main()
{
    long long a, b,sum;
    int d;
    cin >> a >> b >> d;
    sum = a+b;
    if(sum == 0)
    {
        cout<<'0'<<endl;
        return 0;
    }
    int i = 1;
    while(sum)
    {
        aa.push_back(sum%d);
        sum /= d;
    }
    for(i = aa.size()-1;i>=0;i--)
        cout<<aa[i];
    return 0;
}
