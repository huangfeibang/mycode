#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int d, N;
    cin >> d >> N;
    vector<string> a[N+1];
    a[0].push_back('d');
    cout << a[0][0];
    return 0;
}
