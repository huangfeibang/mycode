#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
const double pi=3.1415926535;
int count(char *a);
int youxiao(char *a);
double zhuan(char *a);
double rand(double a,int n); 
int baoliu(double a,int n);
int cheng(char *a,char *b ,double *ans);
char **cut(char *a,int *n);
int chengchu(char *a,char *b);
int jiajian(char *a,char *b);
int jiajian2(char *a,char *b);
int zhishu(double a);
int main()
{
	int n,i,weishu,En,N;
	int weishuf,weishuEf;//第五题变量 
	int weishuEK;//第十题变量 
	int k1=4,k2=4,k3=-6,q1=3,q2=3,q3=3,ndata;//第四题变量 
	int du,fen,bqdfen,p,q,weishuk;//du是度的系数,fen是分的系数,bqdfen是不确定度 
	int n1,n2,n3;
	double shuju[50],sum=0,x,x1,deltA,deltB,U,x0,E,S,f,Uy;
	double Uf,Ef;//第五题变量 
	double k,EK,UK;//第十题变量 
	double Us;
	char aaa[20][20],question[5000];//题目输入 
	char **data;
	double ans,x2,x3,x4,x5,x6;//第九题变量 
	//system(mshta vbscript:msgbox("我是提示内容",64,"我是提示标题")(window.close)); 
	//MessageBox(NULL, "风格豆腐干反对", "_共和国和￣)", MB_ICONEXCLAMATION|MB_OK);
	while(1)
	{
    printf("请输入题号NO\n");
	printf("NO=");
	scanf("%d",&N);
	if(N==1)//第一题 
	{
	    printf("请输入仪器初始读数x0\n");
		printf("x0=");
		scanf("%lf",&x0);
		/*printf("请输入仪器误差限(或者B类不确定度)\n");
		printf("delB=");*/
		deltB=0.004;sum=0;
		//scanf("%lf",&deltB);
		/*printf("请输入数据个数n\n") ;
		printf("n=");
		scanf("%d",&n);*/
		n=6;
		printf("请分别输入6个数据(一个数据一个回车)\n") ; 
		for(i=0;i<=n;i++)
		{
			if(i>=1)    printf("d%d=",i);
			gets(aaa[i]);
		}//为什么从0开始 
		printf("\n");
		for(i=0;i<=n;i++)
		{
			shuju[i]=zhuan(aaa[i]);//把字符串转换为小数 
		}
		for(i=1;i<=n;i++)
		{
		    sum=sum+shuju[i];//对数据求和 
		}
		x=sum/n;//求数据平均值 
		weishu=youxiao(aaa[n-1]);//原始数据的有效位数 
		weishu=baoliu(x,weishu);
		x=rand(x,weishu+1);//中间过程多保留1位有效数字 
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
		printf("d(平均)=%.*lf\n",weishu+1,rand(x,weishu+1));
		printf("d(修正)=%.*lf\n",weishu,rand(x1,weishu));
		printf("S(标准偏差)=%.*lf\n",baoliu(S,2),rand(S,baoliu(S,2)));
		printf("Ud(不确定度)=%.*lf\n",baoliu(U,2),rand(U,baoliu(U,2)));
		printf("d(结果)=%.*lf±%.*lf\n",baoliu(U,1),rand(x1,baoliu(U,1)),baoliu(U,1),rand(U,baoliu(U,1)));
		printf("Ed(相对不确定度)=%.*lf%%\n",En,E);
		printf("\n\n\n");		
	}
	else if(N==2)//第二题 
	{
		x0=0 ;deltB=0.1;n=4;sum=0;
	    /*printf("请输入仪器初始读数x0\n");
		printf("x0=");
		scanf("%lf",&x0);*/
		/*printf("请输入仪器误差限(或者B类不确定度)\n");
		printf("ΔB=");
		scanf("%lf",&deltB);*/
		/*printf("请输入数据个数n\n") ;
		printf("n=");
		scanf("%d",&n);*/
		printf("请输入4个数据(一个数据一个回车)\n");
		for(i=0;i<=n;i++)
		{
			if(i>=1)    printf("x%d=",i);
			gets(aaa[i]);
		}//为什么从0开始 
		printf("\n");
		for(i=0;i<=n;i++)
		{
			shuju[i]=zhuan(aaa[i]);
		}
		for(i=1;i<=n;i++)
		{
		    sum=sum+shuju[i];
		}
		x=sum/n;
		weishu=youxiao(aaa[n-1]);
		weishu=baoliu(x,weishu);
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
				case 2: deltA=9.0*S;
				        deltA=rand(deltA,baoliu(deltA,2));
				        break;
				case 3: deltA=2.5*S;
				        deltA=rand(deltA,baoliu(deltA,2));
				        break;
				case 4: deltA=1.6*S;
				        deltA=rand(deltA,baoliu(deltA,2));
				        break;
				case 5: deltA=1.2*S;
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
		//printf("x(修正)=%.*lf\n",weishu,rand(x1,weishu));
		printf("Sx(标准偏差)=%.*lf\n",baoliu(S,2),rand(S,baoliu(S,2)));
		printf("Ux(不确定度)=%.*lf\n",baoliu(U,2),rand(U,baoliu(U,2)));
		printf("x(结果)=%.*lf±%.*lf\n",baoliu(U,1),rand(x1,baoliu(U,1)),baoliu(U,1),rand(U,baoliu(U,1)));
		printf("Ex(相对不确定度)=%.*lf%%\n",En,E);	
		printf("\n\n\n");
	}
	else if(N==3)//第三题 
	{
		sum=0;
		int wans,wEUa,wEUb;
		double ans,EUa,EUb;
		char Ua[10],Ub[10],liangcheng[10],jibie[10];
		gets(Ua);
		printf("请输入a的读数\n");
		gets(Ua);
		printf("请输入b的读数\n");
		gets(Ub);
		printf("请输入量程\n");
		printf("量程=");
		gets(liangcheng); 
		printf("请输入级别\n");
		printf("级别=");
		gets(jibie);
		printf("\n");
		wans=cheng(liangcheng,jibie,&ans);
		EUa=zhuan(liangcheng)*zhuan(jibie)/zhuan(Ua)*20;
		wEUa=EUa>=10?baoliu(EUa,2):baoliu(EUa,1);
		EUb=zhuan(liangcheng)*zhuan(jibie)/zhuan(Ub)*20;
		wEUb=EUb>=10?baoliu(EUb,2):baoliu(EUb,1);
		printf("Va=%.2lf±%.*lf\n",rand(zhuan(Ua)/20,2),wans,ans);
		printf("E=%.*lf%%\n",wEUa,EUa);
		printf("Vb=%.2lf±%.*lf\n",rand(zhuan(Ub)/20,2),wans,ans);
		printf("E=%.*lf%%\n",wEUb,EUb);
		printf("\n\n\n");
		 
	}
	else if(N==4)//第四题 
	{
		gets(question);
		printf("请将题目复制于此\n"); 
		//gets(question);
		gets(question);
		data=cut(question,&ndata);
		printf("S=k1x+y/k2+k3z\n");
		printf("请输入k1,k2,k3(数据之间以空格隔开) \n");
		scanf("%d%d%d",&k1,&k2,&k3);
		printf("f=x^q1*y^q2/z^q3\n");
		printf("请输入q1,q2,q3(数据之间以空格隔开)\n");
		scanf("%d%d%d",&q1,&q2,&q3);
//		int i,wUs,wUf,weishuEf;//weishuE是 Ef的位数 
		for(i=1;i<=6;i++)
		{
			shuju[i]=zhuan(data[i]);
		}
		weishu=count(data[2]);
		Us=sqrt(k1*k1*shuju[2]*shuju[2]+shuju[4]*shuju[4]/(k2*k2)+shuju[6]*shuju[6]*k3*k3);
		Us=rand(Us,baoliu(Us,2));
		Ef=sqrt(q1*q1*(shuju[2]/shuju[1])*(shuju[2]/shuju[1])+q2*q2*(shuju[4]/shuju[3])*(shuju[4]/shuju[3])+q3*q3*(shuju[6]/shuju[5])*(shuju[6]/shuju[5]));
		weishuEf=Ef*100>=10?baoliu(Ef,2):baoliu(Ef,1);
		S=k1*shuju[1]+shuju[3]/k2+shuju[5]*k3;
		S=rand(S,baoliu(Us,1));
		f=pow(shuju[1],q1)*pow(shuju[3],q2)/pow(shuju[5],q3);
		f=rand(f,weishu+1);
		Uf=f*Ef;
		printf("\n");
		printf("Us=%.*lf%\n",baoliu(Us,2),rand(Us,baoliu(Us,2)));
		printf("S=%.*lf±%.*lf%\n",baoliu(Us,1),S,baoliu(Us,1),Us);
		printf("Uf=%.*lf%\n",baoliu(Uf,2),rand(Uf,baoliu(Uf,2)));
		printf("f=%.*lf±%.*lf\n",baoliu(Uf,1),f,baoliu(Uf,1),rand(Uf,baoliu(Uf,2)));
		printf("\n\n\n");
		
	}
	else if(N==5)//第五题 
	{
		char  S0[20];
		n=6;x0=0;deltB=0.1;sum=0;
		printf("请输入x的数据(一个数据一个回车)\n");
		for(i=0;i<=n;i++)
		{
			if(i>=1)    printf("x%d=",i);
			gets(aaa[i]);
		}//为什么从0开始 
		printf("请输入S0\n"); 
		gets(S0);
		printf("\n");
		for(i=0;i<=n;i++)
		{
			shuju[i]=zhuan(aaa[i]);
		}
		for(i=1;i<=n;i++)
		{
		    sum=sum+shuju[i];
		}
		x=sum/n;
		weishu=youxiao(aaa[n-1]);
		weishu=baoliu(x,weishu);
		x=rand(x,weishu+1);
		//printf("%.*lf",weishu,f);
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
		weishuf=count(S0)<(weishu+1)?count(S0):weishu+1;
		f=rand(x1-zhuan(S0),weishuf);
		Uf=sqrt(0.01+U*U);
		Uf=rand(Uf,baoliu(Uf,2));
		Ef=Uf/f*100.0;
		weishuEf=Ef>=10?baoliu(Ef,2):baoliu(Ef,1);
		printf("x(平均)=%.*lf\n",weishu+1,rand(x,weishu+1));
		printf("f=%.*lf\n",weishuf,f);
		printf("Sx(x的标准偏差)=%.*lf\n",baoliu(S,2),rand(S,baoliu(S,2)));
		printf("Ux(x的不确定度)=%.*lf\n",baoliu(U,2),rand(U,baoliu(U,2)));
		printf("Uf=%.*lf\n",baoliu(Uf,2),Uf);
		printf("f=%.*lf±%.*lf\n",baoliu(Uf,1),rand(f,baoliu(Uf,1)),baoliu(Uf,1),rand(Uf,baoliu(Uf,1)));
		printf("Ef(相对不确定度)=%.*lf%%\n",weishuEf,Ef);
		printf("\n\n\n");				
	}
	else if(N==6)//第六题 
	{
		sum=0;
		/*printf("六.已知θ=n°p′±q′，y=sinθ，\n");
		printf("请输入n,p,q\n") ;
		scanf("%d%d%d",&du,&p,&q);*/
		gets(question);
		printf("请将题目复制于此\n"); 
		//gets(question);
		gets(question);
		data=cut(question,&ndata);
		du=zhuan(data[1]);
		p=zhuan(data[2]);
		q=zhuan(data[3]);
		Uy=fabs(cos((du+p/60.0)*pi/180))*q*pi/180/60;
		Uy=rand(Uy,baoliu(Uy,2));
		printf("y=%.*lf±%.*lf\n",baoliu(Uy,1),sin((du+p/60.0)*pi/180),baoliu(Uy,1),Uy);
		printf("\n\n\n");
	} 
	else if(N==7)//第七题 
	{
		gets(question);
		for(i=1;i<=4;i++)
		{
			printf("请复制第(%d)题表达式(只输入表达式,请勿输入题目编号)\n",i); 
			gets(question);
			data=cut(question,&n);
			U=zhuan(data[2]) ;
			ans=zhuan(data[1]) ;
			if(i!=3)
			{
				weishu=baoliu(U,1);
				ans=zhuan(data[1]);
				printf("%.*lf±%.*lf\n",weishu,ans,weishu,U);					
			}
			else
			{
				ans=ans/pow(10,zhishu(zhuan(data[1])));
				U=U/pow(10,zhishu(zhuan(data[1])));
				weishu=baoliu(U,1);
				printf("%.*lf±%.*lf×10exp%d\n",weishu,ans,weishu,U,zhishu(zhuan(data[1])));	
			}		
		}
		if(i==5)
		{
			printf("请复制第(5)题表达式(只输入表达式,请勿输入题目编号)\n"); 
			gets(question);
			data=cut(question,&n);
			ans=zhuan(data[1]) ;
			weishu=zhishu(ans);	
			ans=ans/pow(10,weishu);
			weishu=baoliu(ans,youxiao(data[1]));
			 printf("%.*lf×10exp%d\n",weishu,ans,zhishu(zhuan(data[1]))+1);
		}		
	}
	else if(N==8)//第八题 
	{
		gets(aaa[1]);
		for(i=1;i<=5;i++)
		{
			printf("请复制输入数据(只复制数据,勿连题目编号一起复制)\n"); 
		    gets(aaa[i]);
		    data=cut(aaa[i],&n);
		    ans=zhuan(data[1]);
		    weishu=zhishu(ans);
		    ans=ans/pow(10,weishu);
		    ans=rand(ans,baoliu(ans,3));
		    printf("%d位  %.*lf×10exp%d\n",youxiao(data[1]),baoliu(ans,3),ans,weishu);			
		}
	}
	else if(N==9)//第九题 
	{
		gets(question);
		for(i=1;i<=5;i++)
		{
			if(i<=4)
			    printf("请复制第(%d)小题表达式(只输入表达式,请勿输入题目编号)\n",i); 
			else
			    printf("请输入第(%d)小题R的值(只输入R的值)\n",i);
			gets(question);
			data=cut(question,&n);
			if(i==1)
			{
		    	weishu=count(data[1]);
				ans=rand(zhuan(data[1])/zhuan(data[2]),weishu);	
		    	printf("%s÷%s=%.*lf\n",data[1],data[2],weishu,ans);	
		    	printf("%s÷%s=%.*lf(整数不影响有效位数,保留%d位有效位数)",data[1],data[2],weishu,ans,youxiao(data[1]));
			}
			else if(i==2)
			{
				//ans=zhuan(data[1])/(zhuan(data[2])-zhuan(data[3]));
				p=jiajian(data[2],data[3]);//p是有效位数 
				x=zhuan(data[2])-zhuan(data[3]);
				x=rand(x,baoliu(x,p));
				ans=zhuan(data[1])/(zhuan(data[2])-zhuan(data[3]));
				q=youxiao(data[1]);
				weishu=baoliu(ans,p<q?p:q);
				n=baoliu(x,p);
				if(n==0)    weishu=count(data[1]);
				ans=rand(ans,weishu);
				printf("%s÷(%s-%s)=%.*lf\n",data[1],data[2],data[3],weishu,ans);
				printf("step1：%s-%s=%.*lf(加减法结果最后一位与参与运算的各数中最后一位位数高者相同)\n",data[2],data[3],baoliu(x,p),x);
				printf("step2：%s÷%.*lf=%.*lf(乘除法的有效位数一般与各数字中有效位数最少的一个相同)\n",data[1],baoliu(x,p),x,weishu,ans);
			}
			else if(i==3)
			{
				k1=jiajian(data[1],data[2]);
				k2=jiajian(data[3],data[4]);
				x1=zhuan(data[1])-zhuan(data[2]);
				x2=zhuan(data[3])-zhuan(data[4]);
				x1=rand(x1,baoliu(x1,k1));
				x2=rand(x2,baoliu(x1,k2));
				ans=x1/x2;
				weishu=baoliu(ans,k1<k2?k1:k2);
				printf("(%s-%s)÷(%s-%s)=%.*lf\n",data[1],data[2],data[3],data[4],weishu,ans);
				printf("step1:%s-%s=%.*lf(加减法结果最后一位与参与运算的各数中最后一位位数高者相同)\n",data[1],data[2],baoliu(x1,k1),x1);
				printf("step2:%s-%s=%.*lf(加减法结果最后一位与参与运算的各数中最后一位位数高者相同)\n",data[3],data[4],baoliu(x2,k2),x2);
				printf("step3:%.*lf÷%.*lf=%.*lf(乘除法的有效位数一般与各数字中有效位数最少的一个相同)\n",baoliu(x1,k1),x1,baoliu(x2,k2),x2,weishu,ans);

				/*n=baoliu(x,q);
				if(n==0)    weishu=baoliu(x1,p);*/
			}
			else if(i==4)
			{
				k1=jiajian(data[2],data[3]);
				k2=jiajian(data[4],data[5]);	
				k3=jiajian2(data[6],data[7]);
				x1=zhuan(data[2]);x2=zhuan(data[3]);x3=zhuan(data[4]);x4=zhuan(data[5]);
				x5=zhuan(data[6]);x6=zhuan(data[7]);
				x1=x1-x2;
				x2=x3-x4;
				x3=x5+x6;
				x1=rand(x1,baoliu(x1,k1));
				x2=rand(x2,baoliu(x2,k2));
				x3=rand(x3,baoliu(x3,k3));
				k1=k1<k2?k1:k2;	
				k1=k1<k3?k1:k3;
				k1=k1<youxiao(data[1])?	k1:youxiao(data[1]);
				ans=zhuan(data[1])*x1/(x2*x3);
				weishu=baoliu(ans,k1);
				printf("%s×(%s-%s)÷[(%s-%s)×(%s+%s])]=%.*lf\n",data[1],data[2],data[3],data[4],data[5],data[6],data[7],weishu,ans) ;
				printf("step1:%s-%s=%.*lf\n",data[2],data[3],baoliu(x1,k1),x1);
				printf("step2:%s-%s=%.*lf\n",data[4],data[5],baoliu(x2,k2),x2);
				printf("step3:%s+%s=%.*lf\n",data[6],data[7],baoliu(x3,k3),x3);
				printf("step4:%s×%.*lf÷(%.*lf×%.*lf)=%.*lf\n",data[1],baoliu(x1,k1),x1,baoliu(x2,k2),x2,baoliu(x3,k3),x3,weishu,ans);
			}
			else if(i==5)
			{
				weishu=youxiao(data[1]);
				n1=baoliu(pi,weishu+1);//n1是pi的小数位数 
				x=rand(pi,n1);
				ans=x*zhuan(data[1])*zhuan(data[1]);
				weishu=baoliu(ans,weishu);
				ans=rand(ans,weishu);
				printf("step1:π=%.*lf(π是公认的常量，参加计算可取比结果多一位来计算，但不影响有效位数)\n",n1,x); 
				printf("step2:S=πR^2=%.*lf×%s×%s=%.*lf\n",n1,x,data[1],data[1],weishu,ans);
			} 
			printf("\n\n");
		}
	}

    else if(N==10)
	{
	    /*printf("请输入仪器初始读数x0\n");
		printf("x0=");
		scanf("%lf",&x0);*/
		/*printf("请输入仪器误差限(或者B类不确定度)\n");
		printf("delB=");*/
		deltB=0.071;x0=0.0;
		sum=0;
		//scanf("%lf",&deltB);
		/*printf("请输入数据个数n\n") ;
		printf("n=");
		scanf("%d",&n);*/
		n=6;
		printf("请输入12个y的数据(P的数据不需要,一个数据一个回车)\n") ; 
		for(i=0;i<=12;i++)
		{
			if(i>=1)    printf("y%d=",i);
			gets(aaa[i]);
		}//为什么从0开始 
		printf("\n");
		for(i=1;i<=n;i++)
		{
			shuju[i]=zhuan(aaa[i+6])-zhuan(aaa[i]);
		}
		//printf("%lf",shuju[6]);
		for(i=1;i<=n;i++)
		{
		    sum=sum+shuju[i];
		}
		x=sum/n;
		weishu=youxiao(aaa[10]);
		weishu=baoliu(x,weishu);
		x=rand(x,weishu+1);
		//printf("%lf\n",x);
		x1=rand(x-x0,weishu);
		sum=0;
		for(i=1;i<=n;i++)
		{
			sum=sum+(shuju[i]-x1)*(shuju[i]-x1);
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
		E=U/x1;
		En=baoliu(E,2);
		E=rand(E,En);
		EK=sqrt(E*E+0.0059*0.0059);
		weishuEK=baoliu(EK,2);
		EK=rand(EK,weishuEK);
		k=12.00/x/10*9.80665;
		weishuk=baoliu(k,(youxiao(aaa[10])+1)<4?(youxiao(aaa[10])+1):4);
		printf("Δy(平均)=%.*lf\n",weishu,x1);
		printf("Δp=12.00\n");
		printf("K=%.*lf\n",weishuk,rand(k,weishuk));
		printf("EΔy=%.*lf\n",En,E);
		printf("EΔp=0.0059\n");
		printf("EK=%.*lf\n",weishuEK,EK);
		printf("Uk=%.*lf\n",baoliu(k*EK,2),rand(k*EK,baoliu(EK*k,2)));
		printf("K=%.*lf±%.*lf\n",baoliu(EK*k,1),rand(k,baoliu(EK*k,1)),baoliu(EK*k,1),rand(EK*k,baoliu(EK*k,1)));
		printf("EK=%.*lf%%\n",baoliu(EK*100,1),EK*100);	
		printf("数据处理过程如下：\n");
		printf("Δy1=%s-%s=%.2lfcm  Δy2=%s-%s=%.2lfcm   Δy3=%s-%s=%.2lfcm   Δy4=%s-%s=%.2lfcm   Δy5=%s-%s=%.2lfcm   Δy6=%s-%s=%.2lfcm   \n"
		,aaa[7],aaa[1],shuju[1],aaa[8],aaa[2],shuju[2],aaa[9],aaa[3],shuju[3],aaa[10],aaa[4],shuju[4],aaa[11],aaa[5],shuju[5],aaa[12],aaa[6],shuju[6]);
		printf("Δy(平均)=(∑（i from 1 to 6)(Δyi))/6=%.*lfcm    (中间运算过程多保留一位)\n",weishu,x1) ;
        printf("Δp(平均)=(∑（i from 1 to 6)(Δpi))/6=12.00g   (乘除法法则，整数不影响有效位数，保留4位有效数字)\n") ;	
        printf("k=F/x=Δpg/Δy=12.00×9.80665÷(%.*lf×10)=%.*lfN/m   (乘除法的有效位数一般与各数字中有效位数最少的一个相同)\n",weishu,x1,weishuk,rand(k,weishuk));
        printf("ΔA=√((∑（i from 1 to 6 )(Δyi-Δy(平均))^2)/(6-1))=%.*lfcm   （中间运算过程保留2位）\n",baoliu(deltA,2),deltA);
        printf("ΔB=√2×Δ仪y=1.41×0.05=0.71cm   （隔项逐差法把n/2近似理解为直接测量量，重复测量了n/2次，)ΔB=√2×Δ仪）\n");
        printf("UΔy=√(ΔA^2+ΔB^2)=%.*lfcm   （不确定度中间运算过程保留2位）\n",baoliu(U,2),U);
        printf("EΔy=UΔy/Δy(平均)=%.*lf÷%.*lf=%.*lf   （相对不确定度中间运算过程通常保留2位）\n",baoliu(U,2),U,weishu,x1,En,E);
        printf("UΔp=ΔBp=Δ仪p×√2=0.05×√2=0.05×1.41=0.71g   (隔项逐差法把n/2近似理解为直接测量量，重复测量了n/2次，ΔB=√2×Δ仪,这里的p为等差数列,ΔA=0)\n");
        printf("EΔP=UΔp/ΔP=0.71÷12.00=0.0059   (相对不确定度中间运算过程通常保留2位）\n");
        printf("Ek=√(EΔy^2+EΔP^2)=%.√(%.*lf^2+0.0059^2+)=%.*lf   （相对不确定度中间运算过程通常保留2位）\n",En,E,weishuEK,EK);
        printf("Uk=Ek×k=%.*lf×%.*lf=%.*lfN/m   （不确定度中间运算过程保留2位）\n",weishuEK,EK,weishuk,rand(k,weishuk),baoliu(k*EK,2),rand(k*EK,baoliu(EK*k,2)));
		printf("K=%.*lf±%.*lfN/m   （不确定度结果保留1位，测量值与不确定度最后一位对齐)\n",baoliu(EK*k,1),rand(k,baoliu(EK*k,1)),baoliu(EK*k,1),rand(EK*k,baoliu(EK*k,1)));
		printf("Ek=Uk/k=%.*lf÷%.*lf=%.*lf%%   (相对不确定度结果小于0.1取1位，大于等于0.1取2位)\n",baoliu(EK*k,1),rand(EK*k,baoliu(EK*k,1)),baoliu(EK*k,1),rand(k,baoliu(EK*k,1)),baoliu(EK*100,1),EK*100);
		printf("\n\n\n");	
	}
	else if(N==11)
	{
        printf("请输入仪器初始读数x0\n");
		printf("x0=");
		scanf("%lf",&x0);
		printf("请输入仪器误差限(或者B类不确定度)\n");
		printf("delB=");
		deltB=0.004;sum=0;
		scanf("%lf",&deltB);
		printf("请输入数据个数n\n") ;
		printf("n=");
		scanf("%d",&n);
		n=6;
		printf("请分别输入n个数据(一个数据一个回车)\n") ; 
		for(i=0;i<=n;i++)
		{
			if(i>=1)    printf("d%d=",i);
			gets(aaa[i]);
		}//为什么从0开始 
		printf("\n");
		for(i=0;i<=n;i++)
		{
			shuju[i]=zhuan(aaa[i]);//把字符串转换为小数 
		}
		for(i=1;i<=n;i++)
		{
		    sum=sum+shuju[i];//对数据求和 
		}
		x=sum/n;//求数据平均值 
		weishu=youxiao(aaa[n-1]);//原始数据的有效位数 
		weishu=baoliu(x,weishu);
		x=rand(x,weishu+1);//中间过程多保留1位有效数字 
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
		printf("d(平均)=%.*lf\n",weishu+1,rand(x,weishu+1));
		printf("d(修正)=%.*lf\n",weishu,rand(x1,weishu));
		printf("S(标准偏差)=%.*lf\n",baoliu(S,2),rand(S,baoliu(S,2)));
		printf("Ud(不确定度)=%.*lf\n",baoliu(U,2),rand(U,baoliu(U,2)));
		printf("d(结果)=%.*lf±%.*lf\n",baoliu(U,1),rand(x1,baoliu(U,1)),baoliu(U,1),rand(U,baoliu(U,1)));
		printf("Ed(相对不确定度)=%.*lf%%\n",En,E);
		printf("\n\n\n");		
	}
	
	else
	{
	    printf("by huangfeibang\n"); 
	    printf("qq:1058677384\n");
	    MessageBox(NULL, "_(┐「ε:)_    _(:3 」∠)_    (￣y▽￣)", "输错了哦!", MB_ICONEXCLAMATION|MB_OK);

	}
	}
	system("pause");
	return 0;
}
int count(char *a)//判断一个数据字符串有多少位小数 
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
int youxiao(char *a)//判断一个 数有多少位有效位数 
{
	int lena=strlen(a),i,start=lena,f=0;
	for(i=0;i<=lena;i++)
	{
		if(*(a+i)>'0'&&*(a+i)<='9')
		{
		    start=i;
		    break;
		}
	}
	for(i=start;i<=lena;i++)
	{
		if(*(a+i)=='.')    f=1;
	}
	return lena-start-f;
}
double zhuan(char *a)//将字符串转换成小数 
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
double rand(double a,int n)//对一个数四舍五入并保留n位小数 
{
	if(a>=0) return int(a*pow(10.0,n)+0.500000001)/pow(10.0,n);
	else return int(a*pow(10.0,n)-0.500000001)/pow(10.0,n);
}
int baoliu(double a,int n)//一个数保留n位有效位数应该保留几位小数 
{
	double b=a;
	int i=0;
	if(fabs(b)<1)
	{
		while(fabs(b)<1)
		{
			b=b*10;
			i++;
		}
		//return i-1+n; 
		if(rand(a,i-1+n)>=1)    return i-2+n;
		else    return i-1+n;    		
	}
	else
	{
		while(fabs(b)>=1)
		{
			b=b/10;
			i--;
		}
		return i+n;		
	}
}
int cheng(char *a,char *b,double *ans)//两个数相乘后应该应该保留的小数位数 
{
	int ya=youxiao(a),yb=youxiao(b),answeishu;//ya是a的有效数字,yb是b的有效位数 ,answeishu是结果积应保留的小数位数 
	double aa,bb;//把a,b转换为浮点数 
	aa=zhuan(a);
	bb=zhuan(b);
	answeishu=baoliu(aa*bb/100,ya<yb?ya:yb);
	aa=(rand((aa*bb/100),answeishu));
	*ans=aa;
	return answeishu;
 
}
char **cut(char *a,int *n)//把字符串里大于等于0的数提取出来 
{
	int i,j=1,k,f;
	char **b;
	b=(char **)malloc(500*sizeof(char *));
	//printf("dsf"); 
	for(i=0;i<50*sizeof(char *);i++)
	{
		b[i]=(char *)malloc(1000);
	}
	for(i=0;i<strlen(a);i++)
	{
		k=0;f=0;
		while(a[i]=='.'||(a[i]>='0'&&a[i]<='9'))
		{
			b[j][k]=a[i];
			k++;
			f=1;
			i++;
		}
		b[j][k]='\0' ; 
		j=j+f;
	}
	*n=j-1;		
	return b;
} 
int jiajian(char *a,char *b)//两个数相减应该后的结果的有效数字 
{
	int counta ,countb,weishuans,youxiaoa,youxiaob,i=0;
	double ans1,aa,bb;
	counta=count(a);
	countb=count(b);
	youxiaoa=youxiao(a);
	youxiaob=youxiao(b);
	aa=zhuan(a);
	bb=zhuan(b);
	ans1=aa-bb;
	while(ans1+0.000000001>=1)
	{
		ans1=ans1/10;
		i++;
	}
	return counta<countb?counta+i:countb+i;
}
int jiajian2(char *a,char *b)//两个数相加应该后的结果的有效数字 
{
	int counta ,countb,weishuans,youxiaoa,youxiaob,i=0;
	double ans;
	counta=count(a);
	countb=count(b);
	youxiaoa=youxiao(a);
	youxiaob=youxiao(b);
	ans=zhuan(a)+zhuan(b);
	while(ans+0.00000001>=1)
	{
		ans=ans/10;
		i++;
	}
	return counta<countb?counta+i:countb+i;
}
int zhishu(double a)//判断一个数是10的多少次方 
{
	int n=0; 
	
	if(a>=10)
	{
		while(a>=10)
		{
			a=a/10.0;
			n++; 
		}
		return n;		
	}
	else
	{
		while(a<1)
		{
			a=a*10.0;
			n--; 
		}
		return n;		
	}	 
}
