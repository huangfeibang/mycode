#include<iostream>
using namespace std;
int P(int a,int da);
int main()
{
    int A, B, DA, DB, x;
    int PA = 0, PB = 0;
    cin>>A>>DA>>B>>DB;
    cout<<P(A,DA) + P(B,DB)<<endl;

}
int P(int a, int da)
{
    int x, ans = 0;
    while(a)
    {
        x = a%10;
        if(x == da)
            ans = ans*10+x;
        a /= 10;
    }
    return ans;
}
