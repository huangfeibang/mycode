#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
typedef struct{
    double huocun, zongjia;
    double danjia;
}moomcake;
vector<moomcake> a;
bool comp(const moomcake &a,const moomcake &b)
{
    return a.danjia>b.danjia;
}
int main()
{
    int N, D;
    moomcake x;
    cin >> N >> D;
    for(int i = 0;i<N;i++)
    {
        cin >>x.huocun;
        a.push_back(x);
    }
    for(int i = 0;i<N;i++)
        cin >>a[i].zongjia;
    for(int i = 0;i<N;i++)
        a[i].danjia = a[i].zongjia*1.0/a[i].huocun;
    sort(a.begin(),a.end(),comp);
    double money = 0.0;
    int i = 0;
    for(int i = 0;i<N;i++)
    {
        if(D<a[i].huocun)
        {
             money += D*a[i].danjia;
             break;
        }
        else
            money += a[i].zongjia;
        D =D - a[i].huocun;
    }
    printf("%.2f\n",money);
    return 0;
}
