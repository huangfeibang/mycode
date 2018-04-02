#include<stdio.h>
long long int quickMod(long long int a,long long int b,long long int c)  
{  
    long long int ans = 1;  
    while (b)  
    {  
  
        if (b % 2 == 1)  
            ans = (ans * a) % c;  
        b /= 2;  
        a = (a * a) % c;  
    }  
    return ans;  
}  
int main()
{
	long long int a=200090,k=3009000,m=30009000909,c;
	c=quickMod(a,k,m);
	printf("%lld\n",c);
	return 0;
}
