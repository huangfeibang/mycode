#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string a, b;
    string x[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> a >> b;
    int lena;
    char timeh, xingqi;
    lena = a.length();
    int f = 0;
    for(int i = 0;i < lena;i++)
    {
        if(a[i] == b[i] && f == 0 && a[i] >= 'A' && a[i] <= 'G')
        {
            xingqi = a[i];
            f = 1;
            continue;
        }
        if(a[i] == b[i] && f == 1 && (a[i] >= '0' &&a[i] <= '9' || a[i] >= 'A' && a[i] <= 'N'))
        {
            timeh = a[i];
            break;
        }
    }

    cin >> a >> b;
    lena = a.length();
    int i;
    for(i = 0;i < lena;i++)
    {
        if(!(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z'))
            continue;
        if(a[i] == b[i])
            break;
    }
    if(xingqi>='a' && xingqi <= 'z')
        xingqi -= 32;
    xingqi -= 'A';
    cout << x[xingqi];
    if(timeh >= '0' && timeh <= '9')
        printf(" %02d", timeh-48);
    else if(timeh >= 'a' && timeh <= 'n')
        printf(" %d", timeh - 'a' +10);
    else
        printf(" %d", timeh - 'A' +10);
    printf(":%02d\n", i);
    return 0;
}
