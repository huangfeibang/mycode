#include<stdio.h>
int main()
{
   int a,b;
   while(scanf("%d%d",&a,&b)==2) //利用scanf的返回值
   {
       printf("%d\n",a+b);
   }
   return 0;
}
