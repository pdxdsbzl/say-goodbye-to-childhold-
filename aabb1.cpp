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
//	mciSendString("open ./ԭ��֮��.mp3", 0, 0, 0);
//	mciSendString("play ./ԭ��֮��.mp3 repeat", 0, 0, 0);//�������repeat�����ظ�����
//	if (0)
//	{
//		mciSendString("close ./ԭ��֮��.mp3", 0, 0, 0);
//	}
//}
//void change()
//{
//	HWND hnd = GetHWnd();
//	SetWindowText(hnd, "ԭ������");
//	int isok=MessageBox(hnd, "����ԭ����", "��ʾ", MB_OKCANCEL);
//	if (isok == IDOK)
//	{
//		outtextxy(250, 250, "ԭ����Ҳ��ԭ�񣡣�");
//	}
//	else
//	{
//		outtextxy(250, 250, "û��ԭ��������ǲ������ģ���");
//	}
//}
//int main()
//{
//	initgraph(900, 900);
//	setbkcolor(WHITE);
//	cleardevice();
//	IMAGE img2,img1;
//	loadimage(&img2, "./����.jpg", 900, 900);
//	putimage(0, 0, &img2);
//	loadimage(&img1, "./����2.0�汾.jpg", 900, 900);
//	putimage(0, 0, &img1);
//	setlinestyle(PS_SOLID, 10);
//	setfillcolor(YELLOW);
//	setlinecolor(RED);
//	circle(50, 50, 50);
//	fillcircle(50, 150, 50);
//	solidcircle(50, 250, 50);
//	settextcolor(GREEN);
//	outtextxy(100, 100, "ԭ����������");
//	fillrectangle(200, 50, 500, 100);
//	char arr[] = "ӭ�����ǵ�����";
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
//					printf("���ǰ�ť�ұ�����");
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