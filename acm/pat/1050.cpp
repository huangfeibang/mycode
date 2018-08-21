#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int N, x, a, b;
    cin >> N;
    vector<int> list(N);
    for(int i = 0;i<N;i++)
        cin >> list[i];
    x = sqrt(N+0.5);
   while(N % x)
        x --;
    a = N / x;
    b = x;
    vector< vector<int> > map(a);
    for(int i = 0;i < a;i++)
        map[i].resize(b);
    sort(list.begin(),list.end(), greater<int>());
    int A = a, B = b;//a是下边界, b是右边界
    int c = 0, d = 0, k = 0, i;//c是上边界, d是左边界
    while(k < N)
    {
        for(i = d; i < b && k < N;i++)
           map[c][i] =list[k++];
        for(c++, i = c; i < a && k < N;i++)
           map[i][b-1] =list[k++];
        for(b--, i = b-1; i >= d && k < N;i--)
           map[a-1][i] =list[k++];
        for(a--, i = a-1; i >= c && k < N;i--)
           map[i][d] =list[k++];
        d++;
    }
    for(int i = 0; i < A;i++)
    {
        for(int j = 0;j < B-1;j++)
            printf("%d ",map[i][j]);
        cout << map[i][B-1]<<endl;
    }
    return 0;
}
