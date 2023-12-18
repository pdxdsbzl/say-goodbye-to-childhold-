//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdbool.h>
//#include<graphics.h>
//#include<string.h>
//#include<mmsystem.h>
//#include<conio.h>
//#pragma comment(lib,"winmm.lib")
//
//void BGM()
//{
//	mciSendString("open ./原神之声.mp3", 0, 0, 0);
//	mciSendString("play ./原神之声.mp3 repeat", 0, 0, 0);//这里加上repeat可以重复播放
//	if (0)
//	{
//		mciSendString("close ./原神之声.mp3", 0, 0, 0);
//	}
//}
//void change()
//{
//	HWND hnd = GetHWnd();
//	SetWindowText(hnd, "原神启动");
//	int isok=MessageBox(hnd, "你玩原神吗", "提示", MB_OKCANCEL);
//	if (isok == IDOK)
//	{
//		outtextxy(250, 250, "原来你也玩原神！！");
//	}
//	else
//	{
//		outtextxy(250, 250, "没有原神的世界是不完整的！！");
//	}
//}
//int main()
//{
//	initgraph(900, 900);
//	setbkcolor(WHITE);
//	cleardevice();
//	IMAGE img2,img1;
//	loadimage(&img2, "./进入.jpg", 900, 900);
//	putimage(0, 0, &img2);
//	loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
//	putimage(0, 0, &img1);
//	setlinestyle(PS_SOLID, 10);
//	setfillcolor(YELLOW);
//	setlinecolor(RED);
//	circle(50, 50, 50);
//	fillcircle(50, 150, 50);
//	solidcircle(50, 250, 50);
//	settextcolor(GREEN);
//	outtextxy(100, 100, "原神启动！！");
//	fillrectangle(200, 50, 500, 100);
//	char arr[] = "迎接你们的王！";
//	int width = (500 - 200) / 2 - textwidth(arr) / 2;
//	int height = (100 - 50) / 2 - textheight(arr) / 2;
//	outtextxy(width + 200, height + 50, arr);
//	BGM();
//	change();
//	ExMessage msg;
//	while(1)
//	{
//		if (peekmessage(&msg, EM_MOUSE))
//		{
//			switch (msg.message)
//			{
//			case WM_LBUTTONDOWN:
//				if (msg.x>=200&&msg.x<=500&&msg.y>=50&&msg.y<=100)
//				{
//					printf("我是按钮我被点了");
//				}
//				break;
//			default:
//					break;
//			}
//		}
//	}
//
//
//
//	getchar();
//	closegraph();
//	return 0;
//}