#include<iostream>
#include<cstdio>
using namespace std;
int main()
{

    int a[129] ={0}, max = 0;
    int c;
    while((c = getchar()) != '\n')
        if(c >= 'a' && c <='z' || c >= 'A' && c <='Z')
        {
            if(c >= 'A' && c <='Z')
                c += 32;
            a[c]++;
            if(a[c] > max)
                max = a[c];
        }
    for(int i = 'a';i <= 'z';i++)
        if(a[i] == max)
        {
              printf("%c %d\n",i, max);
              break;
        }
    return 0;
}
