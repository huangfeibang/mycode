#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)

class caipu
{
	public:
		char caiming[20];
		int pingfen;
		int jiaqian;
};
class dingdan
{
	public:
		char xuhao[10];
		char shijian[20];
		char caiming[50];
		int jiage;
		dingdan* shengcheng();
};
class yonghu
{
	public:
		char yonghuming[20];
		int xingbie;
		int dengji;
		char password[20];
};

int zhuce(yonghu *a);
int xiugai(dingdan* a);
int shanchu(dingdan *a);
int chakan(dingdan* a);
int denglu(yonghu *a);
yonghu* zhuce();
int guanli(yonghu *a);
int N;//订单数量全局 
int M = 0;//用户数量全局 
void setColor(unsigned short ForeColor, unsigned short BackGroundColor)

{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄

	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色

}
int main()
{
	system("color 80");
	int n;
	dingdan *zhangdan = NULL;
	while (1)
	{
		cout<<"********************************************\n";
		cout << "              ";
		setColor(11, 9);
		printf("酒店点菜管理系统\n");
		setColor(0, 8);
		cout<<"********************************************\n";
		cout << "**************权限管理请输入: 1*************\n";
		cout << "**************点餐功能请输入: 2*************\n";
		cout << "**************订单管理请输入: 3*************\n";
		cout << "**************结账管理请输入: 4*************\n";
		cout << "**************查看历史请输入: 5*************\n";
		cout << "**************菜谱评分请输入: 6*************\n";
		cin >> n;
		getchar();
		system("cls");
		if (n == 1)
		{
			yonghu *user;
			user = (yonghu*)malloc(sizeof(yonghu));
			cout << "********************************************\n";
			cout << "              ";
			setColor(11, 9);
			printf("权限管理系统\n");
			setColor(15, 0);
			cout << "****************************************\n";
			cout << "**************注册请输入: 1*************\n";
			cout << "**************登录请输入: 2*************\n";
			cout << "**************用户管理请输入: 3*********\n";
			cout << "*****************退出系统: 4************\n";
			while (scanf("%d", &n) == 1)
			{
				getchar();
				system("cls");
				if (n == 1)
					zhuce(user);
				else if (n == 2)
				{
					denglu(user);
				}
				else if (n == 3)
				{
					guanli(user);
				}
				else
				{
					break;
				}
				cout << "********************************************\n";
				cout << "              ";
				setColor(11, 9);
				printf("权限管理系统\n");
				setColor(15, 0);
				cout << "****************************************\n";
				cout << "**************注册请输入: 1*************\n";
				cout << "**************登录请输入: 2*************\n";
				cout << "**************用户管理请输入: 3*********\n";
				cout << "*****************退出系统: 4************\n";
			}
		}
		else if (n == 2)
		{
			while (scanf("%d", &n) == 1)
			{

			}

		}
		else if (n == 3)
		{
			cout << "********************************************\n";
			cout << "              ";
			setColor(11, 9);
			cout << "酒店点菜管理系统\n";
			setColor(0, 8);
			cout << "********************************************\n";
			cout << "**************生成订单请输入: 1*************\n";
			cout << "**************修改订单请输入: 2*************\n";
			cout << "**************删除订单请输入: 3*************\n";
			cout << "**************查看订单请输入: 4*************\n";
			cout << "*****************退出系统: 4****************\n";
			while (scanf("%d", &n) == 1)
			{
				getchar();
				system("cls");
				if (n == 1)
				{
					zhangdan = shengcheng();
				}
				else if (n == 2)
				{
					xiugai(zhangdan);
				}
				else if (n == 3)
				{
					shanchu(zhangdan);
				}
				else if (n == 4)
				{
					chakan(zhangdan);
				}
				else
					break;
				cout << "********************************************\n";
				printf("              ");
				setColor(11, 9);
				printf("酒店点菜管理系统\n");
				setColor(15, 0);
				cout << "********************************************\n";
				cout << "**************生成订单请输入: 1*************\n";
				cout << "**************修改订单请输入: 2*************\n";
				cout << "**************删除订单请输入: 3*************\n";
				cout << "**************查看订单请输入: 4*************\n";
				cout << "*****************退出系统: 5****************\n";
			}
		}
		else if (n == 4)
		{
			while (1)
			{

			}
		}
		else if (n == 5)
		{
			while (scanf("%d", &n) == 1)
			{

			}
		}
		else
		{
			while (scanf("%d", &n) == 1)
			{

			}
		}
	}

	return 0;
}
dingdan :: dingdan* shengcheng()
{

	dingdan *a;
	int i = 0;
	cout << "请输入订单数量:";
	scanf("%d", &N);
	a = (dingdan *)malloc(sizeof(dingdan)*N);
	while (i<N)
	{
		setColor(10, 3);
		cout << "请输入订单: %d\n", i + 1;
		i++;
		cout << "订单号   时间     菜名 价格\n";
		setColor(11, 5);
		cin >> a[i].xuhao >> a[i].shijian >> a[i].caiming >> a[i].jiage;
	}
	system("pause");
	system("cls");
	system("color 2f");
	getchar();
	return a;
}
int chakan(dingdan* a)
{
	int i;
	char xuhao[20];
	cout << "请输入订单号\n";
	cin >> xuhao;
	for (i = 0; i<N; i++)
	{
		if (strcmp(a[i].xuhao, xuhao) == 0)
		{
			cout << "订单号   时间     菜名 价格\n";
			cout << a[i].xuhao << a[i].shijian << a[i].caiming << a[i].jiage;
			system("pause");
			system("cls");
			return 1;
		}
	}
	printf("没找到您想要的订单\n");
	system("pause");
	system("cls");
	return 0;
}
int xiugai(dingdan* a)
{
	int i, n;
	char xuhao[20];
	printf("请输入要修改的订单号\n");
	cin >> xuhao;
	for (i = 0; i<N; i++)
	{
		if (strcmp(a[i].xuhao, xuhao) == 0)
		{
			cout << "请输入要修改的属性\n";
			cout << "1: 订单号\n2: 时间\n3: 菜名: \n4: 价格\n";
			cin >> n;
			if (n == 1)
			{
				cout << "请输入订单号:\n";
				cin >>a[i].xuhao;
			}
			else if (n == 2)
			{
				cout << "请输入时间:\n";
				cin >>a[i].shijian;
			}
			else if (n == 3)
			{
				cout << "请输入菜名:\n";
				cin >> a[i].caiming;
			}
			else
			{
				cout << "请输入价格:\n";
				cin >> a[i].jiage;
			}
			system("pause");
			system("cls");
			return 1;
		}
	}
	cout << "没找到您想要的订单\n";
	system("pause");
	system("cls");
	return 0;
}
int shanchu(dingdan *a)
{
	int i;
	char xuhao[20];
	cout << "请输入要删除的订单号\n";
	scanf("%s", xuhao);
	for (i = 0; i<N; i++)
	{
		if (strcmp(a[i].xuhao, xuhao) == 0)
		{
			while (i<N)
			{
				a[i + 1] = a[i];
				i++;
			}
			N--;
			cout << "删除完成\n";
			system("pause");
			system("cls");
			return 1;
		}
	}
	cout << "没找到您想要的订单\n";
	system("pause");
	system("cls");
	return 0;
}
int zhuce(yonghu*a)
{
	int i = 0;
	M++;
	char b[20], c[20];
	a = (yonghu *)realloc(a, sizeof(yonghu)*M);
	printf("请输入用户名\n");
	scanf("%s", a[M - 1].yonghuming);
	getchar();
	do {
		printf("请输入密码\n");
		scanf("%s", b);
		getchar();
		printf("再次输入密码\n");
		scanf("%s", c);
		getchar();
		if (strcmp(b, c) == 0)
		{
			strcpy(a[M - 1].password, b);
		}
		else
		{
			printf("两次密码不一致,请重新输入\n");
		}
		system("cls");
	} while (strcmp(b, c));
	printf("请输入您的性别\n1:男  2:女\n");
	scanf("%d", &a[M - 1].xingbie);
	a[M - 1].dengji = 0;
	system("pause");
	system("cls");
	system("color 2f");
	getchar();
	return 0;
}
int denglu(yonghu *a)
{
	int i;
	char yonghuming[20], mima[20];
	printf("请输入用户名\n");
	scanf("%s", yonghuming);
	for (i = 0; i<M; i++)
	{
		if (strcmp(a[i].yonghuming, yonghuming) == 0)
		{

			do
			{
				printf("请输入密码\n");
				scanf("%s", mima);
				printf("用户名      性别  等级\n");
				printf("%s    %2d   %2d\n", a[i].yonghuming, a[i].xingbie, a[i].dengji);
			} while ((strcmp(mima, a[i].password)));
			system("pause");
			system("cls");
			return 1;
		}
	}
	printf(" \n");
	system("pause");
	system("cls");
	return 0;
}
int guanli(yonghu *a)
{
	int i, n;
	char yonghuming[20];
	printf("请输入要修改的用户名\n");
	scanf("%s", yonghuming);
	for (i = 0; i<M; i++)
	{
		if (strcmp(a[i].yonghuming, yonghuming) == 0)
		{
			printf("请输入要修改的属性\n");
			printf("1: 用户名\n2: 性别\n3: 密码: \n4: 等级\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("请输入用户名:\n");
				scanf("%s", a[i].yonghuming);
			}
			else if (n == 2)
			{
				printf("请输入性别:\n1:男 2:女\n");
				scanf("%d", &a[i].xingbie);
			}
			else if (n == 3)
			{
				printf("请输入密码:\n");
				scanf("%s", a[i].password);
			}
			else
			{
				cout << "请输入等级:\n";
				scanf("%d", &a[i].dengji);
			}
			system("pause");
			system("cls");
			return 1;
		}
	}
	cout << "没找到您输入的用户\n";
	system("pause");
	system("cls");
	return 0;
}