#include<cstdio>
int main()
{
    int a[128] = {0};
    char b[6] = {'P', 'A', 'T', 'e', 's', 't'}, c;
    while((c = getchar()) != '\n') a[c]++;
    while(a['P'] >0 || a['A'] >0|| a['T'] >0 || a['e'] >0 || a['s'] >0 || a['t'] >0)
        for(int i = 0;i<6;i++) if(a[b[i]]-- >0) printf("%c",b[i]);
    return 0;
}
