#include<stdio.h>
#include<math.h>
#include<string.h>
int count(char *a);
int youxiao(char *a);
double zhuan(char *a); 
int main()
{
	char aaa[20];
	gets(aaa);
	puts(aaa);
	printf("%d\n",youxiao(aaa));
	printf("%lf\n",zhuan(aaa));
	printf("%d",count(aaa));
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
 
 
