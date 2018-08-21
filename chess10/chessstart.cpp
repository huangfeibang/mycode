#include<stdlib.h>
#include <stdio.h>
#include <direct.h>
#include<string.h>
#include<windows.h>
#define MAXPATH  1024
int main(int argc,char *argv[])
{
	ShowWindow(FindWindow("ConsoleWindowClass",argv[0]),0);//后台静默注册
	FILE *fp;
    char buffer[MAXPATH];
	int i;
	 _getcwd(buffer,MAXPATH);
   //printf("%s",buffer);
   for(i = 0;i<strlen(buffer);i++)//转换格式
   {
   		if(buffer[i] == '\\')
   			buffer[i] = '_';
   }
   fp = fopen("shuxing.bat","w");
   fprintf(fp,"@echo off\nset rr=\"HKEY_CURRENT_USER\\Console\\");//设置路径
   fprintf(fp,"%s",buffer);
   fprintf(fp,"_playchess.exe\"\n");
   fprintf(fp,"reg add %%rr%% /v \"WindowPosition\" /t REG_DWORD /d 0x00000000 /f>nul\n");//窗口位置
   fprintf(fp,"reg add %%rr%% /v \"WindowSize\" /t REG_DWORD /d 0x00140037 /f>nul\n");//窗口大小
   fprintf(fp,"reg add %%rr%% /v \"ScreenBufferSize\" /t REG_DWORD /d 0x00200038 /f>nul\n");//缓冲区大小
   fprintf(fp,"reg add %%rr%% /v \"FullScreen\" /t REG_DWORD /d 0x00000001 /f>nul\n");//全屏//不过似乎无效?
   fprintf(fp,"reg add %%rr%% /v \"FontFamily\" /t REG_DWORD /d 0x00000036 /f>nul\n");//字体
   fprintf(fp,"reg add %%rr%% /v \"FontSize\" /t REG_DWORD /d 0x00480000 /f>nul\n");//字体大小
   fprintf(fp,"reg add %%rr%% /v \"QuickEdit\" /t REG_DWORD /d 0x00000000 /f>nul\n");//关闭快速编辑模式
   fprintf(fp,"start playchess.exe");//启动
    fclose(fp);
	system("shuxing.bat");//执行bat
	//system("taskkill /f /im chessstart.exe");
   //puts(buffer);
   return 0;
}

