#include<stdio.h>
#include<math.h>
#include<string.h>
int count(char *a);
int youxiao(char *a);
double zhuan(char *a);
double rand(double a,int n); 
int baoliu(double a,int n);
int main()
{
	int n,i,weishu,En,N;
	double shuju[50],sum=0,x,x1,deltA,deltB,U,x0,E,S;
	char aaa[20][20];
	printf("请输入仪器初始读数x0\n");
	printf("x0=");
	scanf("%lf",&x0);
	printf("请输入仪器误差限(或者B类不确定度)\n");
	printf("delB=");
	scanf("%lf",&deltB);
	printf("请输入数据个数n\n") ;
	printf("n=");
	scanf("%d",&n);
	printf("请输入数据\n") ; 
	for(i=0;i<=n;i++)
	{
		gets(aaa[i]);
	}//为什么从0开始 
	printf("\n");
	weishu=count(aaa[n-1]);
	for(i=0;i<=n;i++)
	{
		shuju[i]=zhuan(aaa[i]);
	}
	for(i=1;i<=n;i++)
	{
	    sum=sum+shuju[i];
	}
	x=sum/n;
	x=rand(x,weishu+1);
	//printf("%lf\n",x);
	x1=rand(x-x0,weishu);
	sum=0;
	for(i=1;i<=n;i++)
	{
		sum=sum+(shuju[i]-x)*(shuju[i]-x);
	}
    S=sqrt(sum/(n-1));
	S=rand(S,baoliu(S,2));  
	if(n<6)
	{
		switch(n)
		{
			case 2: deltA=9.0*sqrt(sum/(n-1));
			        deltA=rand(deltA,baoliu(deltA,2));
			        break;
			case 3: deltA=2.5*sqrt(sum/(n-1));
			        deltA=rand(deltA,baoliu(deltA,2));
			        break;
			case 4: deltA=1.6*sqrt(sum/(n-1));
			        deltA=rand(deltA,baoliu(deltA,2));
			        break;
			case 5: deltA=1.2*sqrt(sum/(n-1));
			        deltA=rand(deltA,baoliu(deltA,2));
			        break;
		} 
	}
	else
	{
		deltA=sqrt(sum/(n-1));
		deltA=rand(deltA,baoliu(deltA,2));
	}
	U=sqrt(deltA*deltA+deltB*deltB);
	U=rand(U,baoliu(U,2)) ;
	E=U/x1*100.0;
	En=E>=10?baoliu(E,2):baoliu(E,1);
	printf("x(平均)=%.*lf\n",weishu+1,rand(x,weishu+1));
	printf("x(修正)=%.*lf\n",weishu,rand(x1,weishu));
	printf("S(标准偏差)=%.*lf\n",baoliu(S,2),rand(S,baoliu(S,2)));
	printf("U(不确定度)=%.*lf\n",baoliu(U,2),rand(U,baoliu(U,2)));
	printf("x(结果)=%.*lf+_%.*lf\n",baoliu(U,1),rand(x1,baoliu(U,1)),baoliu(U,1),rand(U,baoliu(U,1)));
	printf("E(相对不确定度)=%.*lf%%\n",En,E);
	/*printf("%d\n",youxiao(aaa));
	printf("%lf\n",zhuan(aaa));
	printf("%d",count(aaa));*/
	return 0;
}
int count(char *a)
{
	int lena=strlen(a),i,start=0,finish=0;
	for(i=0;i<=lena;i++)
	{
		if(*(a+i)=='.')    start=i;
		if(*(a+i)=='\0')    finish=i;
	}
	if(start==0)    return 0;
	else return finish-start-1;
}
int youxiao(char *a)
{
	int lena=strlen(a),i,start=lena,f=0;
	for(i=0;i<=lena;i++)
	{
		if(*(a+i)!='0'&&*(a+i)!='-')
		{
		    start=i;
		    break;
		}
	}
	for(i=0;i<=lena;i++)
	{
		if(*(a+i)=='.')    f=1;
	}
	return lena-start-f;
}
double zhuan(char *a)
{
	int lena=strlen(a),f=strlen(a),i;
	double ans=0;
	for(i=0;i<=lena;i++)
	{
		if(*(a+i)=='.' )    f=i;
	}
	for(i=0;i<=lena;i++)
	{
		if(*(a+i)>='0'&& *(a+i)<='9')
		{
			if(i<f)    ans=ans+(*(a+i)-'0')*pow(10,f-i-1);
			else    ans=ans+(*(a+i)-'0')*pow(10,f-i);
		}    
	}
	if(*a=='-')   return -ans;
	else return ans;
}
double rand(double a,int n)
{
	return int(a*pow(10.0,n)+0.5000000001)/pow(10.0,n);
}
int baoliu(double a,int n)
{
	double b=a;
	int i=0;
	while(fabs(a)<1)
	{
		a=a*10;
		i++;
	}
	return i-1+n;
}
 
 
