#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
    string number;
    int shijizuowei;
    int kaoshizuowei;
}student;
int main()
{
    int N, x;
    cin >> N;
    vector<student> a(N);
    for(int i = 0;i<N;i++)
        cin >> a[i].number >> a[i].shijizuowei >> a[i].kaoshizuowei;
    cin >> N;
    for(int i = 0;i < N ;i++)
    {
        cin >> x;
        int j;
        for(j = 0;j<a.size();j++)
        {
            if(a[j].shijizuowei == x)
                break;
        }
        cout << a[j]. number <<' '<<a[j].kaoshizuowei<<endl;
    }
    return 0;
}
