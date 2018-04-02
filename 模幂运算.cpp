#include<stdio.h> 
#include<string.h>
int main()
{
	int ans1[9999] = {1},a,b,c,i=0,ans,j; 
	int ch;
	while(ch!=EOF )
	{
		    ans=1;
			scanf("%d%d%d",&a,&b,&c);
		    while (b)  
		    {  
		        
		        if (b % 2 == 1)  
		        ans = (ans * a) % c;  
		        b /= 2;  
		        a = (a * a) % c;  
		    } 
			i++;
			ans1[i]=ans;
			ch=getchar();
	}
	for(j=1;j<=i;j++)
	{
		printf("%d\n",ans1[j]) ;		
	}
	return 0;
}

