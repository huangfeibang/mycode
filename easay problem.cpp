#include<stdio.h>
int main()
{
	int t,i,n,x;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		if(n==1)
		    printf("Mission Complete!\n");
		else
		printf("Needs at least %d ATP(s)!\n",(n*(n-1))/2);
		
	}
	return 0;
}
