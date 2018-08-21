#include<iostream>
using namespace std;
int main()
{
    int N, num;
    char c;
    cin>>N>>c;
    num = N%2 == 1?N/2+1:N/2;
    for(int j = 0;j<num;j++)
    {

        if(!(j == 0||j == num-1))
        {
            cout<<c;
            for(int i = 0;i<N-2;i++)
                cout<<' ';
            cout<<c;
        }
        else
            for(int i = 0;i<N;i++)
                cout<<c;
        cout<<endl;
    }
    return 0;
}
