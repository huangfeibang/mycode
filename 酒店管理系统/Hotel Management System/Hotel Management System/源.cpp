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
int N;//��������ȫ�� 
int M = 0;//�û�����ȫ�� 
void setColor(unsigned short ForeColor, unsigned short BackGroundColor)

{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ���ھ��

	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//������ɫ

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
		printf("�Ƶ��˹���ϵͳ\n");
		setColor(0, 8);
		cout<<"********************************************\n";
		cout << "**************Ȩ�޹���������: 1*************\n";
		cout << "**************��͹���������: 2*************\n";
		cout << "**************��������������: 3*************\n";
		cout << "**************���˹���������: 4*************\n";
		cout << "**************�鿴��ʷ������: 5*************\n";
		cout << "**************��������������: 6*************\n";
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
			printf("Ȩ�޹���ϵͳ\n");
			setColor(15, 0);
			cout << "****************************************\n";
			cout << "**************ע��������: 1*************\n";
			cout << "**************��¼������: 2*************\n";
			cout << "**************�û�����������: 3*********\n";
			cout << "*****************�˳�ϵͳ: 4************\n";
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
				printf("Ȩ�޹���ϵͳ\n");
				setColor(15, 0);
				cout << "****************************************\n";
				cout << "**************ע��������: 1*************\n";
				cout << "**************��¼������: 2*************\n";
				cout << "**************�û�����������: 3*********\n";
				cout << "*****************�˳�ϵͳ: 4************\n";
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
			cout << "�Ƶ��˹���ϵͳ\n";
			setColor(0, 8);
			cout << "********************************************\n";
			cout << "**************���ɶ���������: 1*************\n";
			cout << "**************�޸Ķ���������: 2*************\n";
			cout << "**************ɾ������������: 3*************\n";
			cout << "**************�鿴����������: 4*************\n";
			cout << "*****************�˳�ϵͳ: 4****************\n";
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
				printf("�Ƶ��˹���ϵͳ\n");
				setColor(15, 0);
				cout << "********************************************\n";
				cout << "**************���ɶ���������: 1*************\n";
				cout << "**************�޸Ķ���������: 2*************\n";
				cout << "**************ɾ������������: 3*************\n";
				cout << "**************�鿴����������: 4*************\n";
				cout << "*****************�˳�ϵͳ: 5****************\n";
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
	cout << "�����붩������:";
	scanf("%d", &N);
	a = (dingdan *)malloc(sizeof(dingdan)*N);
	while (i<N)
	{
		setColor(10, 3);
		cout << "�����붩��: %d\n", i + 1;
		i++;
		cout << "������   ʱ��     ���� �۸�\n";
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
	cout << "�����붩����\n";
	cin >> xuhao;
	for (i = 0; i<N; i++)
	{
		if (strcmp(a[i].xuhao, xuhao) == 0)
		{
			cout << "������   ʱ��     ���� �۸�\n";
			cout << a[i].xuhao << a[i].shijian << a[i].caiming << a[i].jiage;
			system("pause");
			system("cls");
			return 1;
		}
	}
	printf("û�ҵ�����Ҫ�Ķ���\n");
	system("pause");
	system("cls");
	return 0;
}
int xiugai(dingdan* a)
{
	int i, n;
	char xuhao[20];
	printf("������Ҫ�޸ĵĶ�����\n");
	cin >> xuhao;
	for (i = 0; i<N; i++)
	{
		if (strcmp(a[i].xuhao, xuhao) == 0)
		{
			cout << "������Ҫ�޸ĵ�����\n";
			cout << "1: ������\n2: ʱ��\n3: ����: \n4: �۸�\n";
			cin >> n;
			if (n == 1)
			{
				cout << "�����붩����:\n";
				cin >>a[i].xuhao;
			}
			else if (n == 2)
			{
				cout << "������ʱ��:\n";
				cin >>a[i].shijian;
			}
			else if (n == 3)
			{
				cout << "���������:\n";
				cin >> a[i].caiming;
			}
			else
			{
				cout << "������۸�:\n";
				cin >> a[i].jiage;
			}
			system("pause");
			system("cls");
			return 1;
		}
	}
	cout << "û�ҵ�����Ҫ�Ķ���\n";
	system("pause");
	system("cls");
	return 0;
}
int shanchu(dingdan *a)
{
	int i;
	char xuhao[20];
	cout << "������Ҫɾ���Ķ�����\n";
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
			cout << "ɾ�����\n";
			system("pause");
			system("cls");
			return 1;
		}
	}
	cout << "û�ҵ�����Ҫ�Ķ���\n";
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
	printf("�������û���\n");
	scanf("%s", a[M - 1].yonghuming);
	getchar();
	do {
		printf("����������\n");
		scanf("%s", b);
		getchar();
		printf("�ٴ���������\n");
		scanf("%s", c);
		getchar();
		if (strcmp(b, c) == 0)
		{
			strcpy(a[M - 1].password, b);
		}
		else
		{
			printf("�������벻һ��,����������\n");
		}
		system("cls");
	} while (strcmp(b, c));
	printf("�����������Ա�\n1:��  2:Ů\n");
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
	printf("�������û���\n");
	scanf("%s", yonghuming);
	for (i = 0; i<M; i++)
	{
		if (strcmp(a[i].yonghuming, yonghuming) == 0)
		{

			do
			{
				printf("����������\n");
				scanf("%s", mima);
				printf("�û���      �Ա�  �ȼ�\n");
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
	printf("������Ҫ�޸ĵ��û���\n");
	scanf("%s", yonghuming);
	for (i = 0; i<M; i++)
	{
		if (strcmp(a[i].yonghuming, yonghuming) == 0)
		{
			printf("������Ҫ�޸ĵ�����\n");
			printf("1: �û���\n2: �Ա�\n3: ����: \n4: �ȼ�\n");
			scanf("%d", &n);
			if (n == 1)
			{
				printf("�������û���:\n");
				scanf("%s", a[i].yonghuming);
			}
			else if (n == 2)
			{
				printf("�������Ա�:\n1:�� 2:Ů\n");
				scanf("%d", &a[i].xingbie);
			}
			else if (n == 3)
			{
				printf("����������:\n");
				scanf("%s", a[i].password);
			}
			else
			{
				cout << "������ȼ�:\n";
				scanf("%d", &a[i].dengji);
			}
			system("pause");
			system("cls");
			return 1;
		}
	}
	cout << "û�ҵ���������û�\n";
	system("pause");
	system("cls");
	return 0;
}