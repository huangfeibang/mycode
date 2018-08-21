#include<iostream>
using namespace std;
int main()
{
    int a, b ,f = 1;
    while(cin>>a>>b)
    {
        if(b)
        {
            if(f)
            {
                cout<<a*b<<' '<<b-1;
                f = 0;
            }
            else
                cout<<' '<<a*b<<' '<<b-1;
        }
    }
    if(f)
        cout<<"0 0";
    return 0;
}
