#include<stdlib.h>
#include <stdio.h>
#include <direct.h>
#include<string.h>
#include<windows.h>
#define MAXPATH  1024
int main(int argc,char *argv[])
{
	ShowWindow(FindWindow("ConsoleWindowClass",argv[0]),0);//��̨��Ĭע��
	FILE *fp;
    char buffer[MAXPATH];
	int i;
	 _getcwd(buffer,MAXPATH);
   //printf("%s",buffer);
   for(i = 0;i<strlen(buffer);i++)//ת����ʽ
   {
   		if(buffer[i] == '\\')
   			buffer[i] = '_';
   }
   fp = fopen("shuxing.bat","w");
   fprintf(fp,"@echo off\nset rr=\"HKEY_CURRENT_USER\\Console\\");//����·��
   fprintf(fp,"%s",buffer);
   fprintf(fp,"_playchess.exe\"\n");
   fprintf(fp,"reg add %%rr%% /v \"WindowPosition\" /t REG_DWORD /d 0x00000000 /f>nul\n");//����λ��
   fprintf(fp,"reg add %%rr%% /v \"WindowSize\" /t REG_DWORD /d 0x00140037 /f>nul\n");//���ڴ�С
   fprintf(fp,"reg add %%rr%% /v \"ScreenBufferSize\" /t REG_DWORD /d 0x00200038 /f>nul\n");//��������С
   fprintf(fp,"reg add %%rr%% /v \"FullScreen\" /t REG_DWORD /d 0x00000001 /f>nul\n");//ȫ��//�����ƺ���Ч?
   fprintf(fp,"reg add %%rr%% /v \"FontFamily\" /t REG_DWORD /d 0x00000036 /f>nul\n");//����
   fprintf(fp,"reg add %%rr%% /v \"FontSize\" /t REG_DWORD /d 0x00480000 /f>nul\n");//�����С
   fprintf(fp,"reg add %%rr%% /v \"QuickEdit\" /t REG_DWORD /d 0x00000000 /f>nul\n");//�رտ��ٱ༭ģʽ
   fprintf(fp,"start playchess.exe");//����
    fclose(fp);
	system("shuxing.bat");//ִ��bat
	//system("taskkill /f /im chessstart.exe");
   //puts(buffer);
   return 0;
}

