#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
int lenc;//输出结果的位数 
char* jia1(char* a,char* b,int x)//大数加法，传递字符指针 
{
	char *c;//定义char类型的指针 ，用于保存结果 
	int lena,lenb,t,i,f=0,aa,bb;//lena是a的长度，lenb是b的长度 
	lena=strlen(a);
	lenb=strlen(b);
	for(i=x;i<(lena-lenb>0?lena:lenb);i++)//加法运算循环 
	{
		aa=lena-i<=0?48:a[i];//大数a在第i为所贡献的值 
        bb=lenb-i<=0?48:b[i];  //大数b在第i为所贡献的值 
		b[i]=aa+bb+f;//结果b在第i位的值 
		f=0;
		if(b[i]>105)
		{
		    b[i]=b[i]-58;
		    f=1;//标记是否进位 
		}
		else    b[i]=b[i]-48;		
	}
	if(f==1)
	{
		b[i]='1';//判断最后一位是否进位
		lenc=(lena-lenb>0?lena:lenb)+1;//进位则数位+1 
	}
	else  lenc=(lena-lenb>0?lena:lenb);//不进位则为其最长位数的加数位数 
	return b;
}
char* jia(char* a,char* b)//大数加法，传递字符指针 
{
	char *c;//定义char类型的指针 ，用于保存结果 
	int lena,lenb,t,i,f=0,aa,bb;//lena是a的长度，lenb是b的长度 
	lena=strlen(a);
	lenb=strlen(b);
	c=(char*)malloc(lena-lenb>0?(lena+1):(lenb+1));//为 c动态分配空间，空间长度为两加数最长的一个+1 
	for(i=0;i<lena/2;i++)//大数a换序 
	{
		t=a[i];
		a[i]=a[lena-i-1];
		a[lena-i-1]=t;
	}
		for(i=0;i<lenb/2;i++)//大数b换序
	{
		t=b[i];
		b[i]=b[lenb-i-1];
		b[lenb-i-1]=t;
	}
	for(i=0;i<(lena-lenb>0?lena:lenb);i++)//加法运算循环 
	{
		aa=lena-i<=0?48:a[i];//大数a在第i为所贡献的值 
        bb=lenb-i<=0?48:b[i];  //大数b在第i为所贡献的值 
		c[i]=aa+bb+f;//结果c在第i位的值 
		f=0;
		if(c[i]>105)
		{
		    c[i]=c[i]-58;
		    f=1;//标记是否进位 
		}
		else 	c[i]=c[i]-48;	
	}
	if(f==1)
	{
		c[i]='1';//判断最后一位是否进位
		lenc=(lena-lenb>0?lena:lenb)+1;//进位则数位+1 
	}
	else  lenc=(lena-lenb>0?lena:lenb);//不进位则为其最长位数的加数位数 
	return c;
}
char* cheng(char* a,char* b)
{
	int lena,lenb,t,i,f=0,cc,bb,j,k=0,fu=0;//lena是a的长度，lenb是b的长度 ,fu是符号 
	char d[400000]={'0'},*ans;
	lena=strlen(a);
	lenb=strlen(b);
	ans=(char*)malloc(lena+lenb+1);
	for(i=0;i<(lena-lenb>0?lena+2:lenb+2);i++)    *(ans+i)='0';
	*(ans+i)='\0';
	for(i=0;i<lena/2;i++)//大数a换序 
	{
		t=a[i];
		a[i]=a[lena-i-1];
		a[lena-i-1]=t;
	}
		for(i=0;i<lenb/2;i++)//大数b换序
	{
		t=b[i];
		b[i]=b[lenb-i-1];
		b[lenb-i-1]=t;
	}
	if(*(a+lena-1)=='-')
	{
		lena--;
		fu++;
	}
	if(*(b+lenb-1)=='-')
	{
		lenb--;
		fu++;
	}
	if(lena<lenb)
	{
			for(i=0;i<lena;i++)
			{
				f=0;k=i;
				for(j=0;j<lenb;j++)
				{
					d[k]=((a[i]-'0')*(b[j]-'0')+f)%10+'0';
					f=((a[i]-'0')*(b[j]-'0')+f)/10;
					k++;
				}
				d[k]=f+'0';
				k++;
				d[k]='\0';
				ans=jia1(d,ans,i);
				ans[lenc]='\0';
			}
	}
	else
	{
			for(i=0;i<lenb;i++)
			{
				f=0;k=i;
				for(j=0;j<lena;j++)
				{
					d[k]=((a[j]-'0')*(b[i]-'0')+f)%10+'0';
					f=((a[j]-'0')*(b[i]-'0')+f)/10;
					k++;
				}
				d[k]=f+'0';
				k++;
				d[k]='\0';
				ans=jia1(d,ans,i);
				ans[lenc]='\0';
			}
	}
	if(ans[lena+lenb-1]=='0')
	{
		if(fu%2==1)
		{
			ans[lena+lenb-1]='-';
			lenc=lena+lenb;
		}
		else    lenc=lena+lenb-1;
	}   
	else
	{
		if(fu%2==1)
		{
			ans[lena+lenb]='-';
			lenc=lena+lenb+1;
		}
		else    lenc=lena+lenb;
	}
	return ans;
 } 
int main()
{
	char t,a[400000],b[400000],*c,*ans;
	FILE *fp;
	int n,lena,i,lenb;
	clock_t start,finish;
	double time;
	gets(a);
	gets(b); 
	fp=fopen("1.txt","r");
	//fgets(a,20000,fp);
	//fgets(b,20000,fp);
	lena=strlen(a);
	lenb=strlen(b);
	printf("%d\n",lena);
	printf("%d\n",lenb);
	start=clock();
	//printf("%d %d",*a,*b);
	ans=cheng(a,b);
	finish=clock();
	time=finish-start;
	printf("%lf\n",time);  
	for(i=lenc-1;i>=0;i--)
		printf("%c",ans[i]);
		printf("\n");
	//printf("%d\n",lenc);
	//free(c);//释放内存 
	//c=NULL;// 回收指针 
	//free(ans);//释放内存 
	//c=NULL;// 回收指针 
	printf("\n");
	finish=clock();
	time=finish-start;
	printf("%lf\n",time);    
    printf("\n");
    system("pause");
	return 0;
} 
