#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void sort(double *a, int l);
struct Identity{
	int id,rank,pointto[50],pointed[50];
	double sum=0;
	double chance;
};
int main()
{
	
	int m=1,j,i,f=1,weishu,ii,k;
	Identity link[50];
	double A[50][50],M[50],sum=0,p[50],t,n;
	printf("��������ҳ������\n");
	scanf("%lf",&n);	
	if(n<=0||n!=(int)n)
	{
		printf("����������\n"); 
		system("pause");
		return 0;
	}
	//n=(int)n;
	for(i=1;i<=n;i++)
	{
		j=1;
		sum=0;
		printf("�������%d����ҳָ�������,�Կո�������Իس�����\n",i) ;
		do
		{
		    scanf("%d",&link[i].pointto[j++]);
		    link[i].sum++;
		}while(getchar()!='\n');
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(link[i].pointto[j]!=0)  
			    A[link[i].pointto[j]][i]=1/link[i].sum;
		}
	}
 	printf("�������״̬ת�Ƹ��ʾ���������£�\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%lf ",A[i][j]);
			}
			printf("\n");
		}
		printf("page ranking...\n");
		for(i=1;i<=n;i++)
				link[i].id=i;
		for(i=1;i<=n;i++)
		{
			ii
			=1;
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if(link[j].pointto[k]==i)    link[i].pointed[ii++]=link[j].id;
				}
			}
		}
			for(i=1;i<=n;i++)    	M[i]=1/double(n);
		do
		{
			
			for(i=1;i<=n;i++)
			{
				sum=0;
				for(j=1;j<=n;j++)
				{
					sum=sum+A[i][j]*M[j];
				}
				p[i]=sum;
			}
			for(i=1;i<=n;i++)
			{
				t=M[i];
				M[i]=p[i];
				p[i]=t; 
			}
			for(i=1;i<=n;i)			
			{
				if(fabs(M[i]-p[i])>0.00000001) 
				{
					f=0;
					break;
				}
				i++;     
			}
			if(i==(n+1))    f=1;
			m++; 
		if(m>n*n*n*n*999)
        {
        	printf("�û���ת�����޹ؽ��棬���������룡\n");
        	system("pause");
			return 0; 
		}
		}while(f==0);
			sum=0; 
			for(i=1;i<=n;i++)
			{
				sum=sum+M[i];
			}
	
	    	for(i=1;i<=n;i++)
			{
				M[i]=M[i]/sum;
				link[i].chance=M[i];
			}
			sort(M,n);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					if(link[i].chance==M[j])    link[i].rank=j;
				}
			}
			printf("�ļ�ID   PageRankֵ    ����  ������������ID      ��������ҳ��ID\n");
			for(i=1;i<=n;i++)
			{
				f=0;
				printf("%d        %lf      %d      ",link[i].id,link[i].chance,link[i].rank);
				for(j=1;j<=n;j++)
				{
					if(link[i].pointto[j]!=0)
					{
						printf("%d ",link[i].pointto[j] );
						f++;
					}       
				}
				for(k=1;k<=n-f+3;k++)
				{
					printf("  ");
				}
				printf(" ");
				for(j=1;j<=n;j++)
				{
					if(link[i].pointed[j]!=0)
				        printf("%d ",link[i].pointed[j] );
				}
				printf("\n");
		     	//printf("%.5lf\n",M[i]);
		    }
		    system("pause");
			return 0;
 } 
 void sort(double *a, int l)//aΪ�����ַ��lΪ���鳤�ȡ�
{
    int i, j;
    double v;
    //��������
    for(i = 1; i < l ; i ++)
        for(j = i+1; j <=l; j ++)
        {
            if(a[i] < a[j])//��ǰ��ıȺ���Ĵ��򽻻���
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
}

