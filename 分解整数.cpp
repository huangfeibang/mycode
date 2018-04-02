#include<stdio.h>
#include<math.h> 
long long int fenjie(long long int n)//分解整数n 
{
	long long int t,i,b;
	t=sqrt(n);
	if(t*t==n)    return t;
	else
	{
		t++;
		b=t*t-n;
		i=sqrt(b);
		while(i*i!=b)
		{
			t++;
			b=t*t-n;
			i=sqrt(b);
		}
	}
	return t-i;
}
int main()
{
	long long int n;
	while(1)
	{    scanf("%lld",&n);
	printf("%lld",fenjie(n));
		
		}
	return 0;
}
