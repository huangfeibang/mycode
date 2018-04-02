#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *jf(char *p);
char *itoa(int n,char *p);
int main()
{
	char hws[1000000];
	int T,i,n,len,j,f,x;
	gets(hws);
	/*for(i=1;i<=T;i++)
	{
		scanf("%d",&n);  
		x=1;
		while(x==1)
		{
			n++;
			f=1;
			itoa(n,hws);
	    	len=strlen(hws);
			for(j=0;j<len;j++)
			{
		    	if(hws[j]!=hws[len-j-1]) 
		    	{
			    	f=0;
				    break;	
				}
			}
			if(f==1)
			{
				x=0;
				printf("%d\n",n);
			}
		}  
	}*/
	printf("%d\n",hws[1]);
//	puts(hws);
	return 0;
} 
char *itoa(int n,char *p)
{
	int i=0;
	while(n>0)
	{
		p[i++]=n%10+'0';
		n=n/10;
	}
	p[i+1]='\0';
	return(p);
}
void jf(int num)
{
	int len ,i,n;
	len=strlen(p);
	n=p[len-1]-'0'+1;
    return (p[n-1]-'0')==10 ?
	return(p);
}
