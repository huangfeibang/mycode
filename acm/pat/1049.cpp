#include<stdio.h>
int main()
{
    int N;
    double sum = 0, x;
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)
    {
        scanf("%lf", &x);
        sum += x * i * (N-i+1);
    }
    printf("%.2f", sum);
    return 0;
}
