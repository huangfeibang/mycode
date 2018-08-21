#include<stdio.h>
#include<string.h>
int main()
{
    char s[300];
    double x, sum = 0;
    int n, count = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%s", s);
        int len = strlen(s), f = 0, index = 0;
        for(int i = 0;i<len;i++)
        {
            if(s[i] == '.')
            {
                 f++;
                 index = i;
            }
        }
        if(f > 1 || (f == 1 && len - index>3))
            printf("ERROR: %s is not a legal number\n", s);
        else
        {
            if(sscanf(s,"%lf", &x) == 1 && x >= -1000 && x<=1000)
            {
                count++;
                sum += x;
            }
            else
                printf("ERROR: %s is not a legal number\n", s);
        }
    }
    if(count >= 2)
        printf("The average of %d numbers is %.2f\n", count,sum/count);
    else if(count == 1)
        printf("The average of %d number is %.2f\n", count,sum);
    else
        printf("The average of 0 numbers is Undefined\n");
    return 0;
}
