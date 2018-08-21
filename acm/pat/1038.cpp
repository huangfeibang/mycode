#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    vector<int> grade;
    int N, a;
    cin >> N;
    for(int i = 0;i<N;i++)
    {
        cin >> a;
        grade.push_back(a);
    }
    sort(grade.begin(),grade.end());
    cin >> N;
    vector<int> num(N, 0);
    for(int i =0;i<N;i++)
    {
        cin >> a;
        int p = lower_bound(grade.begin(),grade.end(),a) - grade.begin();
        int q = upper_bound(grade.begin(),grade.end(),a) - grade.begin();
        if(p == grade.size() || grade[p] != a)
            num[i] = 0;
        else
            num[i] = q-p;
    }
    for(int i =0;i<N-1;i++)
        printf("%d ", num[i]);
    cout<<num[N-1]<<endl;
    return 0;
}
