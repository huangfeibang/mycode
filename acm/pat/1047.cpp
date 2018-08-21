#include<stdio.h>
int x[1001];
int main()
{
    int a, b, c, N, max = -1, maxi = -1;
    scanf("%d", &N);
    for(int i = 0;i < N;i++)
    {
        scanf("%d-%d%d",&a, &b, &c);
        x[a] += c;
        if(x[a] > max)
        {
            max = x[a];
            maxi = a;
        }
    }
    printf("%d %d", maxi, max);
    return 0;
}
