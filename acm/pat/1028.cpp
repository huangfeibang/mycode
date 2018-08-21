#include<cstdio>
#include<iostream>
using namespace std;
typedef struct{
    char name[7];
    int year;
    int month;
    int day;
}birth;
birth upper, lower;
int comp(const birth &a,const birth &b)
{
    if(a.year<b.year)
        return 1;
    else if(a.year == b.year)
    {
        if(a.month<b.month)
            return 1;
        else if(a.month == b.month)
        {
            if(a.day<b.day)
                return 1;
            else if(a.day==b.day)
                return 0;
            else
                return -1;
        }
        else
            return -1;
    }
    else
        return -1;
}
int main()
{
    birth a, oldest,youngest;
    upper.year = 2014, upper.month = 9, upper.day = 6;
    lower.year = 1814, lower.month = 9, lower.day = 6;
    int n, count = 0, f1 = 0,f2 = 0;
    cin >> n;
    oldest = lower;
    youngest = upper;
    for(int i =0;i<n;i++)
    {
        scanf("%s%d/%d/%d",a.name,&a.year,&a.month,&a.day);
        if(comp(a,upper)>-1 && comp(a,lower)<1)
        {
            if(comp(oldest,a) == 1)
            {
                 oldest = a;
                 f1 = 1;
            }

            if(comp(youngest,a) == -1)
            {
                youngest = a;
                f2 = 1;
            }

            count++;
        }
    }
    cout<<count;
    if(f2&&f1)
    {
      printf(" %s ",youngest.name);
      printf("%s\n",oldest.name);
    }
    else if(f1 == 1&&f2 == 0)
    {
        printf(" %s\n",oldest.name);
    }
    else if(f1 == 0&&f2 == 1)
    {
        printf(" %s\n",youngest.name);
    }
    else
        return 0;
    return 0;
}
