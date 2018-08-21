#include <stdio.h>
#include<stdlib.h>
#include <math.h>
typedef  long long ll;
void extgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b){ d=a; x=1; y=0;}
    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }
}
ll inverse(ll a,ll n){
    ll d,x,y;
    extgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}//拓展欧几里得求逆元 
long long int candp(long long int a,long long int b,long long int c)
{ 
	long long int r=1;
	b=b+1;
	while(b!=1)
	{
	    r=r*a;
	    r=r%c;
	    b--;
	}
	//printf("%lld\n",r);
	return r;
}
long long int quickMod(long long int a,long long int b,long long int c)  //快速幂求余 
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
	long long int p,q,e,d,m,n,t,c,r,k;
	//long long int p1,q1,e1,d1,m1,n1,t1,c1,r1,k1;
	char s;
	printf("加密操作请输入1\n");
	printf("解密操作请输入2\n");
	printf("破解密码请输入3\n");
	scanf("%d",&r);
	while(1)
	{
		switch(r)
		{
			case 1:	printf("请输入大素数p,q: ");
					scanf("%lld%lld",&p,&q);
					n=p*q;
					printf("模数n是 %lld\n",n);
					t=(p-1)*(q-1);
					printf("φ（n）是 %lld\n",t);
					printf("请输入公钥e: ");
					scanf("%lld",&e);
					if(e<1||e>t)
					{
				
					     printf("e是错误的,请重新输入: ");
					     scanf("%lld",&e);
					}
				    d=inverse(e,t);
					printf("经计算私钥d是 %lld\n",d);
			         printf("输入要加密的明文数字: "); /*输入要加密的明文数字*/
		            scanf("%lld",&m);
		            c=quickMod(m,e,n);
		            printf("密文是 %lld\n",c);break;
		    case 2: printf("请输入私钥d"); /*输入要解密的密文数字*/
		            scanf("%lld",&d);
			        printf("输入要解密的密文数字: \n"); /*输入要解密的密文数字*/
		            scanf("%lld",&c);
		            m=quickMod(c,d,n);
		            printf("明文是 %lld\n",m);break;
		    case 3: printf("输入模数n ");
		            scanf("%lld",&n);
		         	printf("输入公钥e ");  
		            scanf("%lld",&e);
		            printf("输入要破解的密文数字: "); 
		            scanf("%lld",&c);
		            p=fenjie(n);
					q=n/p;
					t=(p-1)*(q-1); 
					d=inverse(e,t);
					m=quickMod(c,d,n);
					printf("p=%lld,q=%lld\n密钥d=%lld\n",p,q,d);
					printf("明文是:%lld\n",m);break;
		}
		printf("加密操作请输入1\n");
	    printf("解密操作请输入2\n");
	    printf("破解密码请输入3\n");
		scanf("%lld",&r);
	}
	system("pause");
	return 0; 
}

