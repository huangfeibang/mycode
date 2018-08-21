#include <stdio.h>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include<math.h>

int posx,posy;

void SetPos(int x,int y)
{

    COORD pos;

    HANDLE handle;

    pos.X=y-1;

    pos.Y=x-1;

    handle=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(handle,pos);

}


void setColor(unsigned short ForeColor,unsigned short BackGroundColor)

{

HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄

SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//设置颜色

}


void getpos()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
         posy=csbi.dwCursorPosition.X+1;
		 posx=csbi.dwCursorPosition.Y+1;
    }
}
int main()
{
	while(1)
	{
	    int player,n,time = 120,f = 1;
	    FILE *fp;
	    fp = fopen("player.txt","r");
		fscanf(fp,"%d\n",&n);
		fclose(fp);
		/*getpos();
		if(n == 1)
			SetPos(3,20);
		else
			SetPos(8,20);
		setColor(0,2);
		printf("%d:%d",time/60,time%60);
		SetPos(posx,posy);*/
		do
		{
		    if(f == 1)
                f = 0;
            else
                Sleep(1000);
		    fp = fopen("player.txt","r");
		    fscanf(fp,"%d\n",&player);
		    fclose(fp);
		    getpos();
			if(n == 1)
				SetPos(3,19);
			else
				SetPos(8,19);
			setColor(0,2);
		    printf(" %d:%d  ",time/60,time%60);
		    SetPos(posx,posy);
		    time--;
            if(time<0)
            {
                fp = fopen("chess.txt","w");
                fprintf(fp,"1\nR");
                fclose(fp);
                if(player == 2)
                    MessageBox(NULL, "you lose", "游戏结束", MB_OKCANCEL |MB_ICONERROR);
                else
                    MessageBox(NULL, "you win", "游戏结束", MB_OKCANCEL |MB_ICONERROR);

                return 0;

            }
		}while(n == player);
		getpos();
		if(n == 1)
			SetPos(3,20);
		else
			SetPos(8,20);
		setColor(0,2);
		printf("       ");
		SetPos(posx,posy);
	}
    return 0;
}
