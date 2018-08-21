#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a, b;
    cin >>a >>b;
    int time;
    time = (b-a)/100;
    if((b-a)%100>=50)
        time++;
    printf("%02d:%02d:%02d\n", time/3600, (time%3600)/60, (time%60));
    return 0;
}
