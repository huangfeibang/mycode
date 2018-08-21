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
}//��չŷ���������Ԫ 
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
long long int quickMod(long long int a,long long int b,long long int c)  //���������� 
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
long long int fenjie(long long int n)//�ֽ�����n 
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
	printf("���ܲ���������1\n");
	printf("���ܲ���������2\n");
	printf("�ƽ�����������3\n");
	scanf("%d",&r);
	while(1)
	{
		switch(r)
		{
			case 1:	printf("�����������p,q: ");
					scanf("%lld%lld",&p,&q);
					n=p*q;
					printf("ģ��n�� %lld\n",n);
					t=(p-1)*(q-1);
					printf("�գ�n���� %lld\n",t);
					printf("�����빫Կe: ");
					scanf("%lld",&e);
					if(e<1||e>t)
					{
				
					     printf("e�Ǵ����,����������: ");
					     scanf("%lld",&e);
					}
				    d=inverse(e,t);
					printf("������˽Կd�� %lld\n",d);
			         printf("����Ҫ���ܵ���������: "); /*����Ҫ���ܵ���������*/
		            scanf("%lld",&m);
		            c=quickMod(m,e,n);
		            printf("������ %lld\n",c);break;
		    case 2: printf("������˽Կd"); /*����Ҫ���ܵ���������*/
		            scanf("%lld",&d);
			        printf("����Ҫ���ܵ���������: \n"); /*����Ҫ���ܵ���������*/
		            scanf("%lld",&c);
		            m=quickMod(c,d,n);
		            printf("������ %lld\n",m);break;
		    case 3: printf("����ģ��n ");
		            scanf("%lld",&n);
		         	printf("���빫Կe ");  
		            scanf("%lld",&e);
		            printf("����Ҫ�ƽ����������: "); 
		            scanf("%lld",&c);
		            p=fenjie(n);
					q=n/p;
					t=(p-1)*(q-1); 
					d=inverse(e,t);
					m=quickMod(c,d,n);
					printf("p=%lld,q=%lld\n��Կd=%lld\n",p,q,d);
					printf("������:%lld\n",m);break;
		}
		printf("���ܲ���������1\n");
	    printf("���ܲ���������2\n");
	    printf("�ƽ�����������3\n");
		scanf("%lld",&r);
	}
	system("pause");
	return 0; 
}

