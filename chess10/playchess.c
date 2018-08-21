#include <stdio.h>
#include<conio.h>
#include <windows.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#include <pthread.h>
#include<conio.h>
#include<time.h>

void * time_x(void *);//两个线程
void * chess(void *);

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType);


int MAP1[11][10]={{0,0,0,0,0,0,0,0,0,0},{0,11,12,13,14,15,14,13,12,11,},{0,0,0,0,0,0,0,0,0,0},{0,0,16,0,0,0,0,0,16,0},
	{0,17,0,17,0,17,0,17,0,17},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,27,0,27,0,27,0,27,0,27},
	{0,0,26,0,0,0,0,0,26,0},{0,0,0,0,0,0,0,0,0,0},{0,21,22,23,24,25,24,23,22,21}};//定义初始地图 
int MAP2[11][10]={{0,0,0,0,0,0,0,0,0,0},{0,21,22,23,24,25,24,23,22,21},{0,0,0,0,0,0,0,0,0,0},{0,0,26,0,0,0,0,0,26,0},
	{0,27,0,27,0,27,0,27,0,27},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,17,0,17,0,17,0,17,0,17},
	{0,0,16,0,0,0,0,0,16,0},{0,0,0,0,0,0,0,0,0,0},{0,11,12,13,14,15,14,13,12,11,}};
int map[11][10];//创建地图数组 
int posx=1, posy = 1, pos_x = 1,pos_y = 1, pos1_x;//posx是棋盘坐标,pos_x是光标坐标
int player = 2;//判断是哪个玩家在下,1是对方,2是自己
int self = 1;//判断自己是红方还是黑方,红方是1,黑方是2
/*if(self == 1)
	player = 2;
if(self == 2)
	player = 1;*/
void setColor(unsigned short ForeColor,unsigned short BackGroundColor)

{

HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄

SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//设置颜色

}


//设置光标位置

void SetPos(int x,int y)

{

    COORD pos;

HANDLE handle;

    pos.X=y-1;

    pos.Y=x-1;

    handle=GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(handle,pos);

}


void startmap();//初始化地图


void output(int n, int color)
{
	switch (n)
	{
		case 11:
			setColor(4,color);
			printf("車");
			break;
		case 12:
			setColor(4,color);
			printf("馬");
			break;
		case 13:
			setColor(4,color);
			printf("相");
			break;
		case 14:
			setColor(4,color);
			printf("仕");
			break;
		case 15:
			setColor(4,color);
			printf("帅");
			break;
		case 16:
			setColor(4,color);
			printf("炮");
			break;
		case 17:
			setColor(4,color);
			printf("兵");
			break;
		case 21:
			setColor(0,color);
			printf("車");
			break;
		case 22:
			setColor(0,color);
			printf("馬");
			break;
		case 23:
			setColor(0,color);
			printf("象");
			break;
		case 24:
			setColor(0,color);
			printf("士");
			break;
		case 25:
			setColor(0,color);
			printf("将");
			break;
		case 26:
			setColor(0,color);
			printf("炮");
			break;
		case 27:
			setColor(0,color);
			printf("卒");
			break;
		case 0:
			setColor(7,color);
			printf("");//
			break;
	}
}


int play(int flag1_x,int flag1_y,int flag2_x,int flag2_y);
int main()
{

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = 0; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态


	player = (self == 1?2:1);
	system("start.vbe");//拉起网络进程
	SetConsoleCtrlHandler(HandlerRoutine, TRUE);//控制台异常退出
	//system("shuxing.vbe");//设置窗口属性
	system("cls");
    system("color 2f");
	int i, j,n;
	int color;
	char c;
	int f = 0,flag1_x = -1,flag1_y = -1,flag2_x = -1,flag2_y = -1,flag = 0;
	int shuju[50] ,x;//表示从文件读取到数据;
	FILE *fp;
	fp = fopen("chess.txt","w");
    fprintf(fp,"0\n0000\n");//清除数据
    fclose(fp);
    fp = fopen("chess.txt","w");
    fprintf(fp,"1\nO");
    fclose(fp);
    printf("waite for other\n");
    //system("refresh.exe");//清除缓存
    do
    {
        fp = fopen("chess.txt","r");
            fscanf(fp,"2\n%c\n",&c);
        fclose(fp);
        Sleep(500);
    }while(c!='K' && c!='S');
    if(c == 'K')
    {
     self = 1;
     player = 2;
    }

    else
    {
        self = 2;
        player = 1;
    }
        fp = fopen("chess.txt","w");
        fprintf(fp,"0\n0000");
        fclose(fp);

    system("cls");
    fclose(fp);
	startmap();

    pthread_t t0;
    pthread_t t1;

    // 创建线程A
    if(pthread_create(&t0, NULL, time_x, NULL) == -1){
        puts("fail to create pthread t0");
        exit(1);
    }

    if(pthread_create(&t1, NULL, chess, NULL) == -1){
        puts("fail to create pthread t1");
        exit(1);
    }

    // 等待线程结束
    void * result;
    if(pthread_join(t0, &result) == -1){
        puts("fail to recollect t0");
        exit(1);
    }

    if(pthread_join(t1, &result) == -1){
        puts("fail to recollect t1");
        exit(1);
    }


	//system("starttime.vbe");



return 0;

}



int play(int flag1_x,int flag1_y,int flag2_x,int flag2_y)
{
	int jie1_x, jie1_y, jie2_x, jie2_y, jie3_x, jie3_y, jie4_x, jie4_y;
	int i = flag1_x, j = flag1_y;
	int color;
	int f = 0;
	int count = 0;//中间棋子的计数
	if(self == 1 && map[flag2_x][flag2_y]/10 != player && self == 1 && map[flag2_x][flag2_y]/10 != 0)
	{
		f = 0;
	}
	else if(self == 2 && map[flag2_x][flag2_y]/10 == player)
	{
		f = 0;
	}
	else
	{
		switch(map[flag1_x][flag1_y]%10)//判断棋子的 属性 
		{
			case 1:
				if(flag1_x == flag2_x)
				{
					for(j = (flag1_y < flag2_y ? flag1_y: flag2_y);j<=(flag1_y > flag2_y ? flag1_y: flag2_y);j++)
					{
					    if(map[flag1_x][j])
                                count++;
					}
					if(count == 2 && map[flag2_x][flag2_y])
						f = 1;
                    if(count == 1 && map[flag2_x][flag2_y] == 0)
                        f = 1;
				}
				else if(flag1_y == flag2_y)
				{
					for(i = (flag1_x < flag2_x ? flag1_x: flag2_x);i<=(flag1_x > flag2_x ? flag1_x: flag2_x);i++)
					{
					    if(map[i][flag1_y])
                            count++;
					}
					if(count == 2 && map[flag2_x][flag2_y])
						f = 1;
                    if(count == 1 && map[flag2_x][flag2_y] == 0)
                        f = 1;
				}
				break;
			case 2:
				if((abs(flag2_x -flag1_x) == 1 && abs(flag2_y - flag1_y) == 2) )
				{
					if(map[flag1_x][(flag2_y +flag1_y)/2] == 0)
						f = 1;
				}
				if(abs(flag2_x -flag1_x) == 2 && abs(flag2_y -flag1_y) == 1)
				{
					if(map[(flag2_x + flag1_x)/2][flag1_y] == 0)
						f = 1;
				}
				break;
			case 3:
				if((abs(flag2_x -flag1_x) == 2 && abs(flag2_y -flag1_y) == 2))
				{
					if(flag2_x<=player*5 && flag2_x >= player*5-5 && map[(flag2_x + flag1_x)/2][(flag2_y +flag1_y)/2] == 0)
						f = 1;
				}
				break;
			case 4:
				if((abs(flag2_x -flag1_x) == 1 && abs(flag2_y -flag1_y) == 1))
				{
					if(flag2_y >=4 && flag2_y <=6 && flag2_x >= 1+7*(player-1) && flag2_x <= 3+(player-1)*7)
						f = 1;
					else
						f = 0;
				}
				else
					f = 0;
				break;
			case 5:
				if((abs(flag2_x -flag1_x) == 1 && flag2_y - flag1_y == 0) || flag2_x == flag1_x && abs(flag2_y -flag1_y) == 1)
				{
					if(flag2_y >=4 && flag2_y <=6 && flag2_x >= 1+7*(player-1) && flag2_x <= 3+(player-1)*7)
						f = 1;
				}
				if(map[flag2_x][flag2_y] == 15 && flag1_y == flag2_y)
				{
					for(i = (flag1_x < flag2_x ? flag1_x: flag2_x);i<=(flag1_x > flag2_x ? flag1_x: flag2_x);i++)
					{
						if(map[i][flag2_y])
							count++;
					}
					if(count == 2)
						f = 1;
				}
				break;
			case 6:
					if(map[flag2_x][flag2_y])
					{
						if(flag1_x == flag2_x)
						{
							for(j = (flag1_y < flag2_y ? flag1_y: flag2_y);j<=(flag1_y > flag2_y ? flag1_y: flag2_y);j++)
							{
								if(map[flag1_x][j])
							    	count++;
							}
						}
						if(count == 3)
							f = 1;
						count = 0;
						if(flag1_y == flag2_y)
						{
							for(i = (flag1_x < flag2_x ? flag1_x: flag2_x);i<=(flag1_x > flag2_x ? flag1_x: flag2_x);i++)
							{
								if(map[i][flag1_y])
								count ++;
							}
						}
						if(count == 3)
							f = 1;
					}
					else
					{
                        if(flag1_x == flag2_x)
                        {
                            for(j = (flag1_y < flag2_y ? flag1_y: flag2_y);j<=(flag1_y > flag2_y ? flag1_y: flag2_y);j++)
                            {
                                if(map[flag1_x][j])
                                        count++;
                            }
                            if(count == 2 && map[flag2_x][flag2_y])
                                f = 1;
                            if(count == 1 && map[flag2_x][flag2_y] == 0)
                                f = 1;
                        }
                        else if(flag1_y == flag2_y)
                        {
                            for(i = (flag1_x < flag2_x ? flag1_x: flag2_x);i<=(flag1_x > flag2_x ? flag1_x: flag2_x);i++)
                            {
                                if(map[i][flag1_y])
                                    count++;
                            }
                            if(count == 2 && map[flag2_x][flag2_y])
                                f = 1;
                            if(count == 1 && map[flag2_x][flag2_y] == 0)
                                f = 1;
                        }
					}
					break;
				case 7:
						if(player == 1)
						{
							if(flag1_x <= 5 )
							{
								if(flag2_x -flag1_x == 1 && flag2_y == flag1_y)
									f = 1;
							}
							else
							{
								if((flag2_x -flag1_x == 1 && flag2_y == flag1_y )|| (flag2_x == flag1_x && abs(flag1_y - flag2_y) == 1))
									f = 1;
							}
						}
						else
						{
							if(flag1_x >= 6)
							{
								if(flag2_x -flag1_x == -1 && flag2_y == flag1_y)
									f = 1;
							}
							else
							{
								if(flag2_x -flag1_x == -1 && flag2_y == flag1_y || flag2_x == flag1_x && abs(flag1_y - flag2_y) == 1)
									f = 1;
							}
						}
					break;

		}
	}
	if(f)
	{
		if(map[flag2_x][flag2_y]%10== 5)
		    return player;
    	map[flag2_x][flag2_y] = map[flag1_x][flag1_y];
    	map[flag1_x][flag1_y] = 0;
    	SetPos(flag1_x>5?flag1_x+1:flag1_x,1);
		for(j = 1;j<10;j++)
		{
			color = 2;
			output(map[flag1_x][j],color);
		}
		player = (player+1) %2;
		if(player == 0)
		    player = 2;
		return 0;
	}
	return -1;//表示移动不合法
}
void startmap()
{
    system("color 2f");
	int i, j;
	int color;
	char c;
	int f = 0,flag1_x = -1,flag1_y = -1,flag2_x = -1,flag2_y = -1,flag = 0;
	if(self == 2) //判断自己是红方还是黑方
	{
		memcpy(map, MAP1,sizeof(MAP1));
	}
	else
	{
		memcpy(map, MAP2,sizeof(MAP2));
	}
	for(i = 1;i<11;i++)//初始化棋盘
	{
		for(j = 1;j<10;j++)
		{
			if(i == flag1_x && j ==flag1_y)
				color = 1;
			else if(i == flag2_x && j ==flag2_y)
				color = 1;
			else if(i == posx && j ==posy)
				color = 6;
			else
			    color = 2;
			output(map[i][j],color);
		}
		if(i == 5)
		{
			setColor(11,2);
			printf("\n 楚  河    汉  界 ");
		}
		printf("\n");
	}
}

void * time_x(void *a){

	system("time_x");
    return NULL;

}

// 线程B 方法
void * chess(void *b){

		int i, j,n;
		int color;
		char c;
		int f = 0,flag1_x = -1,flag1_y = -1,flag2_x = -1,flag2_y = -1,flag = 0;
		int shuju[50] ,x;//表示从文件读取到数据;
		FILE *fp;
		n = 1;
		shuju[0] = 0;
while(1)
	{
		 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	    CONSOLE_CURSOR_INFO CursorInfo;
	    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	   	CursorInfo.bVisible = 0; //隐藏控制台光标
	    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

		if(player == 1)
		{
		    fp = fopen("player.txt","w");
		    fprintf(fp,"%d\n",player);//向time程序传达轮到谁下
		    fclose(fp);
			int a;//判断是接收到的还是发送的数据
			fp = fopen("chess.txt","r");
			fscanf(fp,"%d\n%d\n",&a,&x);
			if(x == shuju[n-1] || a != 2)
			{
				fclose(fp);
				Sleep(500);
				continue;
			}
			else
			{
				shuju[n] = x;
				fclose(fp);
			}
			flag1_x = (shuju[n]/1000 == 0?10:shuju[n]/1000);
			flag1_y = ((shuju[n]/100)%10 == 0?10:(shuju[n]/100)%10);
			flag2_x = ((shuju[n]/10)%10 == 0?10:(shuju[n]/10)%10);
			flag2_y = (shuju[n]%10 == 0?10:shuju[n]%10);
			n++;
			int vod;
			vod =  play(flag1_x,flag1_y,flag2_x,flag2_y);
            if(vod == 1)
            {
                int nRet;
                nRet = MessageBox(NULL, "you lose\n是否继续?", "游戏结束", MB_OKCANCEL |MB_ICONERROR);
                if (nRet == IDOK)
                {
                    self = (self == 1?2:1);
                    player = (self == 1?2:1);
                    system("cls");
                    startmap();
                    flag1_x = flag1_y= flag2_y = flag2_x=-1;
                    flag = 0;
                    continue;
                }
                else if (nRet == IDCANCEL)
                {
	                fp = fopen("chess.txt","w");
	                fprintf(fp,"1\nR");
	                fclose(fp);
	                return 0;
				}

            }
            else if(vod == 2)
            {
                fp = fopen("chess.txt","w");
                fprintf(fp,"1\nR");
                fclose(fp);
                int nRet;
                nRet = MessageBox(NULL, "you win\n是否继续?", "游戏结束", MB_OKCANCEL |MB_ICONERROR);
                if (nRet == IDOK)
                {
                    self = (self == 1?2:1);
                    player = (self == 1?2:1);
                    system("cls");
                    startmap();
                    flag1_x = flag1_y= flag2_y = flag2_x=-1;
                    flag = 0;
                    continue;
                }
                else if (nRet == IDCANCEL)
                {
	                fp = fopen("chess.txt","w");
	                fprintf(fp,"1\nR");
	                fclose(fp);
	                return 0;
				}
            }
			pos1_x = flag2_x >5?flag2_x+1:flag2_x;
			SetPos(pos1_x,1);
			for(j = 1;j<10;j++)
			{
				color = 2;
				output(map[flag2_x][j],color);
			}
	        flag1_x = -1;
	  		flag1_y = -1;
	   	    flag2_x = -1;
	        flag2_y = -1;
		}
		if(player == 2)
		{
		    fp = fopen("player.txt","w");//向time程序传达轮到谁下
		    fprintf(fp,"%d\n",player);
		    fclose(fp);
		    int time = 120;
			int bushu = 0;
            c = getch();
			if(c == '2' || c == 's')
			{
				SetPos(pos_x,1);
				for(j = 1;j<10;j++)
				{
					if(posx == flag1_x && j == flag1_y)
						color = 1;
					else if(posx == flag2_x && j ==flag2_y)
						color = 3;
					else
					    color = 2;
					output(map[posx][j],color);
				}
				posx++;
				if(posx>10)
				    posx = posx-10;
				if(posx < 1)
				    posx =posx+10;
				//if(posx == 6)
			}
			else if(c == '4'|| c == 'a')
			{
				posy--;
				if(posy>9)
				    posy = posy-9;
				if(posy < 1)
				    posy =posy+9;
			}
			else if(c == '6'|| c == 'd')
			{
				posy++;
				if(posy>9)
				    posy = posy-9;
				if(posy < 1)
				    posy =posy+9;
			}
			else if(c == '8'|| c == 'w')
			{
				SetPos(pos_x,1);
				for(j = 1;j<10;j++)
				{
					if(posx == flag1_x && j == flag1_y)
						color = 1;
					else if(posx == flag2_x && j ==flag2_y)
						color = 3;
					else
					    color = 2;
					output(map[posx][j],color);
				}
				posx--;
				if(posx>10)
				    posx = posx-10;
				if(posx < 1)
				    posx =posx+10;

			}
			if(posx>5)
				pos_x = posx+1;
			else
				pos_x = posx;
			if(c == '5'|| c == 'j')
			{
				if(flag == 0 && !(flag1_x == posx && flag1_y == posy) && !(flag2_x == posx && flag2_y == posy) && map[posx][posy]/10 == self)//判断是第一次选中还是第二次选中，还要防止重复选中同一个位置//并且选中的是自己的棋子
				{
				    if(flag2_x != -1)
	                {
	                    SetPos(flag2_x>5?flag2_x+1:flag2_x,1);
						for(j = 1;j<10;j++)
						{
	                        if(flag2_x == posx && j ==posy)
	                            color = 15;
	                        else
	                            color = 2;
	                        output(map[flag2_x][j],color);
						}
	                }
	                flag2_x = -1;
					flag2_y = -1;
					if(map[posx][posy])//第一次选中必须有棋子
					{
		                flag1_x = posx;
						flag1_y = posy;
					}
	                flag = 1;

				}
				else if(flag == 1 && !(flag2_x == posx && flag2_y == posy) && !(flag1_x == posx && flag1_y == posy))
				{
					flag2_x = posx;
					flag2_y = posy;
	                SetPos(flag1_x>5?flag1_x+1:flag1_x,1);
	                for(j = 1;j<10;j++)
	                {
	                    if(flag1_x == posx && j == posy)
	                        color = 15;
	                    else
	                        color = 2;
	                        output(map[flag1_x][j],color);
	                }
	                int vod;
	                if(flag1_x!=-1 && flag1_y!=-1 && flag1_y!=-1 && flag1_y!=-1)//两次选中都有效
	                	vod = play(flag1_x,flag1_y,flag2_x,flag2_y);
	                if(vod != -1)
	                {
                        int x;
                        int shuju[50];
                        x = (11-flag1_x)%10*1000 + (10-flag1_y)*100 + (11-flag2_x)%10*10 + 10-flag2_y;
                        fp = fopen("chess.txt","w");
                        fprintf(fp,"1\n%d\n",x);
                        fclose(fp);
                        shuju[bushu++] = x;
	                    if(vod == 1)
                        {
                            int nRet;
                            nRet = MessageBox(NULL, "you lose\n是否继续?", "游戏结束", MB_OKCANCEL |MB_ICONERROR);
                            if (nRet == IDOK)
                            {
                            	self = (self == 1?2:1);
                    			player = (self == 1?2:1);
                                system("cls");
                                startmap();
                                flag1_x = flag1_y= flag2_y = flag2_x=-1;
                                flag = 0;
                                continue;
                            }
                            else if (nRet == IDCANCEL)
                            {
                        		fp = fopen("chess.txt","w");
                        		fprintf(fp,"1\nR");
                        		fclose(fp);
                                return 0;
                            }

                        }
                        else if(vod == 2)
                        {
                            int nRet;
                            nRet = MessageBox(NULL, "you win\n是否继续?", "游戏结束", MB_OKCANCEL |MB_ICONERROR);
                            if (nRet == IDOK)
                            {
                            	self = (self == 1?2:1);
                    			player = (self == 1?2:1);
                                system("cls");
                                startmap();
                                flag1_x = flag1_y= flag2_y = flag2_x=-1;
                                flag = 0;
                                continue;
                            }
                            else if (nRet == IDCANCEL)
                            {
                        		fp = fopen("chess.txt","w");
                        		fprintf(fp,"1\nR");
                        		fclose(fp);
                                return 0;
                            }

                        }

					}
	                flag1_x = -1;
	                flag1_y = -1;
	                flag2_x = -1;
	                flag2_y = -1;
					flag = 0;
				}

			}
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = 0; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
			SetPos(pos_x,1);
			for(j = 1;j<10;j++)
			{
				if(posx == flag1_x && j == flag1_y)
					color = 1;
				else if(posx == flag2_x && j == flag2_y)
					color = 3;
				else if(posx == posx && j ==posy)
					color = 15;
				else
				    color = 2;
				output(map[posx][j],color);
			}
			SetPos(pos_x,1);//防止bug有用,无法解释原理
		}
		}
    return NULL;
}

BOOL WINAPI HandlerRoutine(DWORD dwCtrlType)
{
	FILE *fp;
	// 控制台将要被关闭
    if(CTRL_CLOSE_EVENT == dwCtrlType)
	{
		system("taskkill /f /im chess_web.exe") ;
        fp = fopen("chess.txt","w");
        fprintf(fp,"1\nR");
        fclose(fp);
    }
	return TRUE;
}
