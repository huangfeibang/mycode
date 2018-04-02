#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	
	int n,x,ans[50]={0},i=0,time;
	scanf("%d",&n);
	while(n>0)
	{
		
		scanf("%d",&x);
		time=clock();
		if(x==0)    printf("0\n");
		else
		{
			while(x!=0)
			{
				ans[i++]=x%6;
				x=x/6;
			}
			for(i=i-1;i>=0;i--)
			{
				printf("%d",ans[i]);
			}
			printf("\n");
			i=0;			
		}
		n--;
		time=clock()-time;
		printf("time=%d\n",time);
	}
	return 0;
}
