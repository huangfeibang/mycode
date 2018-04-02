#include <stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
	int n=0;
	double a,b,c,p;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%lf%lf%lf",&a,&b,&c);
		if(a!=0)
		{
			p=b*b-4*a*c;
			c=-b/(2*a);
			b=sqrt(fabs(p))/(2*a);
			if(p<0)
			{
				if(fabs(c)<1e-5)    printf("x1=x2=%.5lfi\n",b);
			    else	printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",c,b,c,b);
			}	
			else if(p==0)
			{
				if(fabs(c)<1e-5)    printf("x1=x2=0\n");
				else    printf("x1=x2=%.5lf\n",c);
			}	
			else
			{
			    if(fabs(c+b)<1e-5)	  printf("x1=0;x2=%.5lf\n",c-b);
			    else if(fabs(c-b)<1e-5)	  printf("x1=%.5lf;x2=0\n",c+b);
			    else if((fabs(c+b)<1e-5)&&(fabs(c-b)<1e-5))   printf("x1=x2=0\n");
				else  printf("x1=%.5lf;x2=%.5lf\n",c+b,c-b);
			}		
		}
		n--;
	}
	return 0;
}
