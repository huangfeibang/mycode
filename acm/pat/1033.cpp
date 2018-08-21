#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

    string str1;
    char c;
    int f = 0;
    while((c = getchar()) != '\n')
    {
        if(c == '+')
            f = 1;
        str1.push_back(c);
    }
    while((c = getchar()) != '\n')
    {
        char d = c;
        if(d >= 'a' && d <= 'z')
            d -= 32;
        int p = str1.find(d);
        if(p == -1 && !f)
            putchar(c);
        if(p == -1 && f && !(c >= 'A' && c <= 'Z'))
            putchar(c);
    }
    cout << endl;
    return 0;
}
