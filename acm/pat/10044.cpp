#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int grade, maxgrade = -1, mingrade = 101, n;
    char num[11],name[11], ansnum1[11],ansname1[11], ansnum2[11],ansname2[11];
    cin >>n;
    while(n)
    {
        scanf("%s%s%d",name,num,&grade);
        if(grade>maxgrade)
        {
            strcpy(ansname1,name);
            strcpy(ansnum1,num);
            maxgrade = grade;
        }
        if(grade<mingrade)
        {
            strcpy(ansname2,name);
            strcpy(ansnum2,num);
            mingrade = grade;
        }
        n--;
    }
    cout<<ansname1<<' '<<ansnum1<<endl;
    cout<<ansname2<<' '<<ansnum2<<endl;
    return 0;
}
