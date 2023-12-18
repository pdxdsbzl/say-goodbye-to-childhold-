#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include<graphics.h>
#include<string.h>
#include<mmsystem.h>
#include<conio.h>
#include<time.h>
#define H 15
#pragma comment(lib,"winmm.lib")
#define BOARD_SIZE 15
int str[15][15] = {0};
int r = 1;
int map[15][15];			
int arr[15][15] = { 0 };
int fat = 1;
int bbq = 1;
int m = 0;
int n = 0;
int row, col;
char player = 'X';
int point = -1;
int bunch = 0;
char board[BOARD_SIZE][BOARD_SIZE];

void BGM()
{
    mciSendString("open ./原神之声.mp3", 0, 0, 0);
    mciSendString("play ./原神之声.mp3 repeat", 0, 0, 0);//这里加上repeat可以重复播放
    if (0)
    {
        mciSendString("close ./原神之声.mp3", 0, 0, 0);
    }
}

void initBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = '.';
        }
    }
}

void printBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(int row, int col)
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
    {
        return false;
    }
    if (board[row][col] != '.')
    {
        return false;
    }
    return true;
}

bool checkWin(int row, int col, char player)
{
    //    int dx[] = {-1, 0, 1, 1}; 
    //    int dy[] = {0, 1, 1, -1};
    int dx[] = { 1, 0, 1, -1 }; // 横、竖、斜、反斜四个方向
    int dy[] = { 0, 1, 1, 1 };
    for (int i = 0; i < 4; i++)
    {
        int count = 1;
        int x = row + dx[i];
        int y = col + dy[i];

        while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == player)
        {
            count++;
            x += dx[i];
            y += dy[i];
        }

        x = row - dx[i];
        y = col - dy[i];

        while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == player)
        {
            count++;
            x -= dx[i];
            y -= dy[i];
        }

        if (count == 5)
        {
            return true;
        }
    }

    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}

void putit()
{
    ExMessage msg;
    initBoard();
    printBoard();
    int flag = 0;
    while (1)
    {
        if (flag == 1)
        {
            /*settextcolor(RED);
            outtextxy(400, 400, "游戏结束！！");*/
            break;
        }
        if (peekmessage(&msg, EM_MOUSE))
        {

            m = (msg.x - 45) / 58;
            n = (msg.y - 45) / 58;
            switch (msg.message)//注意啊，这里的break都是跳出switch，吓死我了，还以为是while
            {
            case WM_LBUTTONDOWN:
                if ((msg.x - 45) % 58 <= 28 && (msg.y - 45) % 58 <= 28)
                {
                    if (arr[m][n] == 1)
                    {
                        HWND hnd = GetHWnd();
                        SetWindowText(hnd, "五子棋启动");
                        int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
                        break;
                    }
                    if (point == 1)
                    {//printf("我是按钮我被点了");
                        setfillcolor(WHITE);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    else
                    {
                        setfillcolor(BLACK);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    arr[m][n] = 1;
					str[n][m] = r;
					r++;
                }
                else  if ((msg.x - 45) % 58 > 28 && (msg.y - 45) % 58 <= 28)
                {
                    m += 1;
                    if (arr[m][n] == 1)
                    {
                        HWND hnd = GetHWnd();
                        SetWindowText(hnd, "五子棋启动");
                        int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
                        break;
                    }
                    if (point == 1)
                    {//printf("我是按钮我被点了");
                        setfillcolor(WHITE);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    else
                    {
                        setfillcolor(BLACK);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    arr[m][n] = 1;
					str[n][m] = r;
					r++;
                }
                else  if ((msg.x - 45) % 58 <= 28 && (msg.y - 45) % 58 > 28)
                {
                    n += 1;
                    if (arr[m][n] == 1)
                    {
                        HWND hnd = GetHWnd();
                        SetWindowText(hnd, "五子棋启动");
                        int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
                        break;
                    }
                    if (point == 1)
                    {//printf("我是按钮我被点了");
                        setfillcolor(WHITE);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    else
                    {
                        setfillcolor(BLACK);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    arr[m][n] = 1;
					str[n][m] = r;
					r++;
                }
                else  if ((msg.x - 45) % 58 > 28 && (msg.y - 45) % 58 > 28)
                {
                    m += 1;
                    n += 1;
                    if (arr[m][n] == 1)
                    {
                        HWND hnd = GetHWnd();
                        SetWindowText(hnd, "五子棋启动");
                        int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
                        break;
                    }
                    if (point == 1)
                    {//printf("我是按钮我被点了");
                        setfillcolor(WHITE);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    else
                    {
                        setfillcolor(BLACK);
                        solidcircle(45 + m * 58, 45 + n * 58, 27);
                        point *= -1;
                    }
                    arr[m][n] = 1;
					str[n][m] = r;
					r++;
                }
                printf("Player %c's turn, enter row (0-%d) and column (0-%d): ", player, BOARD_SIZE - 1, BOARD_SIZE - 1);
                // scanf("%d %d", &row, &col);
                row = n;//这里千万注意！！！！两个的列与行是反的！！！！！
                col = m;
                if (!isValidMove(row, col))
                {
                    printf("Invalid move, try again.\n");
                    continue;
                }
                board[row][col] = player;
                printBoard();//Here we can add qing kong 

                if (checkWin(row, col, player))
                {
                    flag = 1;
                    printf("Player %c wins!\n", player);
                    break;
                }

                if (isBoardFull())
                {
                    printf("It's a draw!\n");
                    break;
                }

                player = (player == 'X') ? 'O' : 'X';
                break;
            default:   break;
            }
        }
    }
}


void ini()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			map[i][j] = 0;
		}
	}
	
}

void check(int x, int y)
{
	int hei = 0, bai = 0;
	bunch = 0;
	for (int i = 0; i < 15; i++)			//横向判断
	{
		if ((map[x][i] == 0) || (map[x][i] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[x][i] == 1) || (map[x][i] == 4))
		{
			hei++;
			bai = 0;
			if (hei == 5)
			{
				//printf("\t\t\t********黑方胜***********\n");
				bunch = 1;
				fat = 1;

			}
		}
		if ((map[x][i] == 2) || (map[x][i] == 5))
		{
			bai++;
			hei = 0;
			if (bai == 5)
			{
				//printf("\t\t\t********白方胜***********\n");
				bunch = 1;
				fat = -1;
			}
		}

	}

	hei = 0, bai = 0;
	for (int i = 0; i < 15; i++)			//纵向判断
	{

		if ((map[i][y] == 0) || (map[i][y] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[i][y] == 1) || (map[i][y] == 4))
		{
			hei++;
			bai = 0;
			if (hei == 5)
			{
				//printf("\t\t\t********黑方胜***********\n");
				bunch = 1;
				fat = 1;
			}
		}
		if ((map[i][y] == 2) || (map[i][y] == 5))
		{
			bai++;
			hei = 0;
			if (bai == 5)
			{
				//printf("\t\t\t********白方胜***********\n");
				bunch = 1;
				fat = -1;
			}
		}
	}

	//斜向(\向)判断
	int x1 = x, y1 = y;
	if (x1 > y1)
	{
		x1 = x1 - y1;
		y1 = 0;
	}
	else
	{
		y1 = y1 - x1;
		x1 = 0;
	}
	hei = 0, bai = 0;
	while ((x1 < H) && (y1 < H))
	{
		if ((map[x1][y1] == 0) || (map[x1][y1] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[x1][y1] == 1) || (map[x1][y1] == 4))
		{
			hei++;
			bai = 0;
			if (hei == 5)
			{
				//printf("\t\t\t********黑方胜***********\n");
				bunch = 1;
				fat = 1;
			}
		}
		if ((map[x1][y1] == 2) || (map[x1][y1] == 5))
		{
			bai++;
			hei = 0;
			if (bai == 5)
			{
				//printf("\t\t\t********白方胜***********\n");
				bunch = 1;
				fat = -1;
			}
		}
		x1++;
		y1++;
	}

	//斜向（/向）判断
	int x2 = x, y2 = y;
	if (x2 > y2)
	{
		x2 = (x - (H - y));
		y2 = H - 1;
	}
	else
	{
		x2 = 0;
		y2 = (y + x);
	}
	hei = 0, bai = 0;
	while ((y2 >= 0) && (x2 < H))
	{
		if ((map[x2][y2] == 0) || (map[x2][y2] == 3))
		{
			hei = 0;
			bai = 0;
		}
		if ((map[x2][y2] == 1) || (map[x2][y2] == 4))
		{
			hei++;
			bai = 0;
			if (hei == 5)
			{
				//printf("\t\t\t********黑方胜***********\n");
				bunch = 1;
				fat = 1;
			}
		}
		if ((map[x2][y2] == 2) || (map[x2][y2] == 5))
		{
			bai++;
			hei = 0;
			if (bai == 5)
			{
				//printf("\t\t\t********白方胜***********\n");
				bunch = 1;
				fat = -1;
			}
		}
		x2++;
		y2--;
	}

}

void putthat()
{
	
	ExMessage msg3;
	//initBoard();
	//printBoard();
	int wind = 0;
	while (1)
	{		
		int map1[15][15] = { 0 };
		int max = map1[0][0];
		int x = 0, y = 0;
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				map1[i][j] = 0;
			}
		}
		if (wind == 1)
		{
			/*settextcolor(RED);
			outtextxy(400, 400, "游戏结束！！");*/
			break;
		}
		if (peekmessage(&msg3, EM_MOUSE))
		{

			m = (msg3.x - 45) / 58;
			n = (msg3.y - 45) / 58;
			switch (msg3.message)//注意啊，这里的break都是跳出switch，吓死我了，还以为是while
			{
			case WM_LBUTTONDOWN:
				if ((msg3.x - 45) % 58 <= 28 && (msg3.y - 45) % 58 <= 28)
				{
					if (arr[m][n] == 1)
					{
						HWND hnd = GetHWnd();
						SetWindowText(hnd, "五子棋启动");
						int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
						break;
					}
					// if (point == 1)
					// {//printf("我是按钮我被点了");
					   //  setfillcolor(WHITE);
					   //  solidcircle(45 + m * 58, 45 + n * 58, 27);
					 //    point *= -1;
					 //}
					// else
					// {
					setfillcolor(BLACK);
					solidcircle(45 + m * 58, 45 + n * 58, 27);
					//  point *= -1;
				 // }
					arr[m][n] = 1;
				}
				else  if ((msg3.x - 45) % 58 > 28 && (msg3.y - 45) % 58 <= 28)
				{
					m += 1;
					if (arr[m][n] == 1)
					{
						HWND hnd = GetHWnd();
						SetWindowText(hnd, "五子棋启动");
						int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
						break;
					}
					//  if (point == 1)
					 // {//printf("我是按钮我被点了");
					  //    setfillcolor(WHITE);
					  //    solidcircle(45 + m * 58, 45 + n * 58, 27);
					  //    point *= -1;
					 // }
					 // else
					 // {
					setfillcolor(BLACK);
					solidcircle(45 + m * 58, 45 + n * 58, 27);
					//point *= -1;
			   // }
					arr[m][n] = 1;
				}
				else  if ((msg3.x - 45) % 58 <= 28 && (msg3.y - 45) % 58 > 28)
				{
					n += 1;
					if (arr[m][n] == 1)
					{
						HWND hnd = GetHWnd();
						SetWindowText(hnd, "五子棋启动");
						int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
						break;
					}
					//  if (point == 1)
					//  {//printf("我是按钮我被点了");
					//      setfillcolor(WHITE);
					//      solidcircle(45 + m * 58, 45 + n * 58, 27);
					  //    point *= -1;
					 // }
					  //else
					 // {
					setfillcolor(BLACK);
					solidcircle(45 + m * 58, 45 + n * 58, 27);
					point *= -1;
					// }
					arr[m][n] = 1;
				}
				else  if ((msg3.x - 45) % 58 > 28 && (msg3.y - 45) % 58 > 28)
				{
					m += 1;
					n += 1;
					if (arr[m][n] == 1)
					{
						HWND hnd = GetHWnd();
						SetWindowText(hnd, "五子棋启动");
						int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
						break;
					}
					//  if (point == 1)
					//  {//printf("我是按钮我被点了");
					  //    setfillcolor(WHITE);
					 //     solidcircle(45 + m * 58, 45 + n * 58, 27);
					  //    point *= -1;
					//  }
					 // else
				   //   {
					setfillcolor(BLACK);
					solidcircle(45 + m * 58, 45 + n * 58, 27);
					//      point *= -1;
				   //   }
					arr[m][n] = 1;
				}
				map[m][n] = 1;
				str[n][m] = r;
				r++;
				//fat = fat * (-1);
				check(m, n);
				if (bunch == 1)
				{
					break;
				}
				//check(x, y);
				//AI
				//int map1[15][15] = { 0 };
				for (int i = 0; i < 15; i++)
				{
					for (int j = 0; j < 15; j++)
					{
						if ((map[i][j] == 0) || (map[i][j] == 3))
						{

							if (((i - 4) > -1))				//纵向
							{
								//堵黑棋
								if (((map[i - 4][j] == 1) || (map[i - 4][j] == 4)) &&((map[i - 3][j] == 1) || (map[i - 3][j] == 4)) && ((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i - 3][j] == 1) || (map[i - 3][j] == 4)) && ((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i - 1][j] == 1) || map[i - 1][j] == 4))
								{
									map1[i][j] += 20;
								}
								//下白棋
								if (((map[i - 4][j] == 2) || (map[i - 4][j] == 5)) && ((map[i - 3][j] == 2) || (map[i - 3][j] == 5)) && ((map[i - 2][j] == 2) || (map[i - 2][j] == 5)) && ((map[i - 1][j] == 2) || map[i - 1][j] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i - 3][j] == 2) || (map[i - 3][j] == 5)) && ((map[i - 2][j] == 2) || (map[i - 2][j] == 5)) && ((map[i - 1][j] == 2) || map[i - 1][j] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i - 2][j] == 2) || (map[i - 2][j] == 5)) && ((map[i - 1][j] == 2) || map[i - 1][j] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i - 1][j] == 2) || map[i - 1][j] == 5))
								{
									map1[i][j] += 10;
								}

							}
							if ((i + 4) < H)
							{
								if (((map[i + 4][j] == 1) || (map[i + 4][j] == 4)) && ((map[i + 3][j] == 1) || (map[i + 3][j] == 4)) && ((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i + 3][j] == 1) || (map[i + 3][j] == 4)) && ((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i + 1][j] == 1) || map[i + 1][j] == 4))
								{
									map1[i][j] += 20;
								}
								if (((map[i + 4][j] == 2) || (map[i + 4][j] == 5)) && ((map[i + 3][j] == 2) || (map[i + 3][j] == 5)) && ((map[i + 2][j] == 2) || (map[i + 2][j] == 5)) && ((map[i + 1][j] == 2) || map[i + 1][j] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i + 3][j] == 2) || (map[i + 3][j] == 5)) && ((map[i + 2][j] == 2) || (map[i + 2][j] == 5)) && ((map[i + 1][j] == 2) || map[i + 1][j] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i + 2][j] == 2) || (map[i + 2][j] == 5)) && ((map[i + 1][j] == 2) || map[i + 1][j] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i + 1][j] == 2) || map[i + 1][j] == 5))
								{
									map1[i][j] += 10;
								}
							}

							if ((j - 4) > -1)			//横向
							{
								//堵黑棋
								if (((map[i][j - 4] == 1) || (map[i][j - 4] == 4)) && ((map[i][j - 3] == 1) || (map[i][j - 3] == 4)) && ((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i][j - 3] == 1) || (map[i][j - 3] == 4)) && ((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i][j - 1] == 1) || map[i][j - 1] == 4))
								{
									map1[i][j] += 20;
								}
								//下白棋
								if (((map[i][j - 4] == 2) || (map[i][j - 4] == 5)) && ((map[i][j - 3] == 2) || (map[i][j - 3] == 5)) && ((map[i][j - 2] == 2) || (map[i][j - 2] == 5)) && ((map[i][j - 1] == 2) || map[i][j - 1] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i][j - 3] == 2) || (map[i][j - 3] == 5)) && ((map[i][j - 2] == 2) || (map[i][j - 2] == 5)) && ((map[i][j - 1] == 2) || map[i][j - 1] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i][j - 2] == 2) || (map[i][j - 2] == 5)) && ((map[i][j - 1] == 2) || map[i][j - 1] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i][j - 1] == 2) || map[i][j - 1] == 5))
								{
									map1[i][j] += 10;
								}
							}
							if ((j + 4) < H)
							{
								if (((map[i][j + 4] == 1) || (map[i][j + 4] == 4)) && ((map[i][j + 3] == 1) || (map[i][j + 3] == 4)) && ((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i][j + 3] == 1) || (map[i][j + 3] == 4)) && ((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i][j + 1] == 1) || map[i][j + 1] == 4))
								{
									map1[i][j] += 20;
								}

								if (((map[i][j + 4] == 2) || (map[i][j + 4] == 5)) && ((map[i][j + 3] == 2) || (map[i][j + 3] == 5)) && ((map[i][j + 2] == 2) || (map[i][j + 2] == 5)) && ((map[i][j + 1] == 2) || map[i][j + 1] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i][j + 3] == 2) || (map[i][j + 3] == 5)) && ((map[i][j + 2] == 2) || (map[i][j + 2] == 5)) && ((map[i][j + 1] == 2) || map[i][j + 1] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i][j + 2] == 2) || (map[i][j + 2] == 5)) && ((map[i][j + 1] == 2) || map[i][j + 1] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i][j + 1] == 2) || map[i][j + 1] == 5))
								{
									map1[i][j] += 10;
								}
							}

							if (((j - 4) > -1) && ((i - 4) > -1))		//  \向
							{
								//堵黑棋
								if (((map[i - 4][j - 4] == 1) || (map[i - 4][j - 4] == 4)) && ((map[i - 3][j - 3] == 1) || (map[i - 3][j - 3] == 4)) && ((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i - 3][j - 3] == 1) || (map[i - 3][j - 3] == 4)) && ((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
								{
									map1[i][j] += 20;
								}
								//下白棋
								if (((map[i - 4][j - 4] == 2) || (map[i - 4][j - 4] == 5)) && ((map[i - 3][j - 3] == 2) || (map[i - 3][j - 3] == 5)) && ((map[i - 2][j - 2] == 2) || (map[i - 2][j - 2] == 5)) && ((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i - 3][j - 3] == 2) || (map[i - 3][j - 3] == 5)) && ((map[i - 2][j - 2] == 2) || (map[i - 2][j - 2] == 5)) && ((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i - 2][j - 2] == 2) || (map[i - 2][j - 2] == 5)) && ((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i - 1][j - 1] == 2) || map[i - 1][j - 1] == 5))
								{
									map1[i][j] += 10;
								}

							}
							if (((j + 4) < H) && ((i + 4) < H))
							{
								if (((map[i + 4][j + 4] == 1) || (map[i + 4][j + 4] == 4)) && ((map[i + 3][j + 3] == 1) || (map[i + 3][j + 3] == 4)) && ((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i + 3][j + 3] == 1) || (map[i + 3][j + 3] == 4)) && ((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
								{
									map1[i][j] += 20;
								}

								if (((map[i + 4][j + 4] == 2) || (map[i + 4][j + 4] == 5)) && ((map[i + 3][j + 3] == 2) || (map[i + 3][j + 3] == 5)) && ((map[i + 2][j + 2] == 2) || (map[i + 2][j + 2] == 5)) && ((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i + 3][j + 3] == 2) || (map[i + 3][j + 3] == 5)) && ((map[i + 2][j + 2] == 2) || (map[i + 2][j + 2] == 5)) && ((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i + 2][j + 2] == 2) || (map[i + 2][j + 2] == 5)) && ((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i + 1][j + 1] == 2) || map[i + 1][j + 1] == 5))
								{
									map1[i][j] += 10;
								}
							}

							if (((i - 4) > -1) && ((j + 4) < H))		//  /向
							{
								//堵黑棋
								if (((map[i - 4][j + 4] == 1) || (map[i - 4][j + 4] == 4)) && ((map[i - 3][j + 3] == 1) || (map[i - 3][j + 3] == 4)) && ((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i - 3][j + 3] == 1) || (map[i - 3][j + 3] == 4)) && ((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
								{
									map1[i][j] += 20;
								}
								//下白棋
								if (((map[i - 4][j + 4] == 2) || (map[i - 4][j + 4] == 5)) && ((map[i - 3][j + 3] == 2) || (map[i - 3][j + 3] == 5)) && ((map[i - 2][j + 2] == 2) || (map[i - 2][j + 2] == 5)) && ((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i - 3][j + 3] == 2) || (map[i - 3][j + 3] == 5)) && ((map[i - 2][j + 2] == 2) || (map[i - 2][j + 2] == 5)) && ((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i - 2][j + 2] == 2) || (map[i - 2][j + 2] == 5)) && ((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i - 1][j + 1] == 2) || map[i - 1][j + 1] == 5))
								{
									map1[i][j] += 10;
								}
							}
							if (((i + 4) < H) && ((j - 4) > -1))
							{
								if (((map[i + 4][j - 4] == 1) || (map[i + 4][j - 4] == 4)) && ((map[i + 3][j - 3] == 1) || (map[i + 3][j - 3] == 4)) && ((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
								{
									map1[i][j] += 100000;
								}
								if (((map[i + 3][j - 3] == 1) || (map[i + 3][j - 3] == 4)) && ((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
								{
									map1[i][j] += 10000;
								}
								if (((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
								{
									map1[i][j] += 500;
								}
								if (((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
								{
									map1[i][j] += 20;
								}

								if (((map[i + 4][j - 4] == 2) || (map[i + 4][j - 4] == 5)) && ((map[i + 3][j - 3] == 2) || (map[i + 3][j - 3] == 5)) && ((map[i + 2][j - 2] == 2) || (map[i + 2][j - 2] == 5)) && ((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
								{
									map1[i][j] += 20000;
								}
								if (((map[i + 3][j - 3] == 2) || (map[i + 3][j - 3] == 5)) && ((map[i + 2][j - 2] == 2) || (map[i + 2][j - 2] == 5)) && ((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
								{
									map1[i][j] += 1000;
								}
								if (((map[i + 2][j - 2] == 2) || (map[i + 2][j - 2] == 5)) && ((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
								{
									map1[i][j] += 50;
								}
								if (((map[i + 1][j - 1] == 2) || map[i + 1][j - 1] == 5))
								{
									map1[i][j] += 10;
								}
							}
						}
					}
				}

				//int x = 0, y = 0;
				/*do
				{
					x = rand() % H;
					y = rand() % H;
				} while ((map[x][y] == 0) || (map[x][y] == 3));*/

				//int max = map1[0][0];
				for (int i = 0; i < H; i++)
				{
					for (int j = 0; j < H; j++)
					{
						if (map1[i][j] > max)
						{
							max = map1[i][j];
							x = i, y = j;
						}
					}
				}
				map[x][y] = 2;
				str[y][x] = r;
				r++;
				for (int i = 0;i <= 14;i++)
				{
					for (int r = 0;r <= 14;r++)
					{
						if (map[i][r] == 2)
						{
							arr[i][r] = 1;
							setfillcolor(WHITE);
							solidcircle(45 + i * 58, 45 + r * 58, 27);
						}
					}
				}
				
				check(x,y);
				break;
			default:   break;
			}
		}
		//fat = fat * (-1);
		if (bunch == 1)
		{
			break;
		}
	}
}

void putbut()
{

		ExMessage msg3;
		//initBoard();
		//printBoard();
		int wind = 0;
		while (1)
		{
			int map1[15][15] = { 0 };
			int max = map1[0][0];
			int x = 0, y = 0;
			for (int i = 0; i < 15; i++)
			{
				for (int j = 0; j < 15; j++)
				{
					map1[i][j] = 0;
				}
			}
			if (wind == 1)
			{
				/*settextcolor(RED);
				outtextxy(400, 400, "游戏结束！！");*/
				break;
			}
			if (peekmessage(&msg3, EM_MOUSE))
			{

				m = (msg3.x - 45) / 58;
				n = (msg3.y - 45) / 58;
				switch (msg3.message)//注意啊，这里的break都是跳出switch，吓死我了，还以为是while
				{
				case WM_LBUTTONDOWN:
					if ((msg3.x - 45) % 58 <= 28 && (msg3.y - 45) % 58 <= 28)
					{
						if (arr[m][n] == 1)
						{
							HWND hnd = GetHWnd();
							SetWindowText(hnd, "五子棋启动");
							int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
							break;
						}
						// if (point == 1)
						// {//printf("我是按钮我被点了");
						   //  setfillcolor(WHITE);
						   //  solidcircle(45 + m * 58, 45 + n * 58, 27);
						 //    point *= -1;
						 //}
						// else
						// {
						setfillcolor(BLACK);
						solidcircle(45 + m * 58, 45 + n * 58, 27);
						//  point *= -1;
					 // }
						arr[m][n] = 1;
					}
					else  if ((msg3.x - 45) % 58 > 28 && (msg3.y - 45) % 58 <= 28)
					{
						m += 1;
						if (arr[m][n] == 1)
						{
							HWND hnd = GetHWnd();
							SetWindowText(hnd, "五子棋启动");
							int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
							break;
						}
						//  if (point == 1)
						 // {//printf("我是按钮我被点了");
						  //    setfillcolor(WHITE);
						  //    solidcircle(45 + m * 58, 45 + n * 58, 27);
						  //    point *= -1;
						 // }
						 // else
						 // {
						setfillcolor(BLACK);
						solidcircle(45 + m * 58, 45 + n * 58, 27);
						//point *= -1;
				   // }
						arr[m][n] = 1;
					}
					else  if ((msg3.x - 45) % 58 <= 28 && (msg3.y - 45) % 58 > 28)
					{
						n += 1;
						if (arr[m][n] == 1)
						{
							HWND hnd = GetHWnd();
							SetWindowText(hnd, "五子棋启动");
							int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
							break;
						}
						//  if (point == 1)
						//  {//printf("我是按钮我被点了");
						//      setfillcolor(WHITE);
						//      solidcircle(45 + m * 58, 45 + n * 58, 27);
						  //    point *= -1;
						 // }
						  //else
						 // {
						setfillcolor(BLACK);
						solidcircle(45 + m * 58, 45 + n * 58, 27);
						point *= -1;
						// }
						arr[m][n] = 1;
					}
					else  if ((msg3.x - 45) % 58 > 28 && (msg3.y - 45) % 58 > 28)
					{
						m += 1;
						n += 1;
						if (arr[m][n] == 1)
						{
							HWND hnd = GetHWnd();
							SetWindowText(hnd, "五子棋启动");
							int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
							break;
						}
						//  if (point == 1)
						//  {//printf("我是按钮我被点了");
						  //    setfillcolor(WHITE);
						 //     solidcircle(45 + m * 58, 45 + n * 58, 27);
						  //    point *= -1;
						//  }
						 // else
					   //   {
						setfillcolor(BLACK);
						solidcircle(45 + m * 58, 45 + n * 58, 27);
						//      point *= -1;
					   //   }
						arr[m][n] = 1;
					}
					map[m][n] = 1;
					str[n][m] = r;
					r++;
					//fat = fat * (-1);
					check(m, n);
					if (bunch == 1)
					{
						break;
					}
					//check(x, y);
					//AI
					//int map1[15][15] = { 0 };
					for (int i = 0; i < 15; i++)
					{
						for (int j = 0; j < 15; j++)
						{
							if ((map[i][j] == 0) || (map[i][j] == 3))
							{

								if (((i - 4) > -1))				//纵向
								{
									//堵黑棋
									if (((map[i - 4][j] == 1) || (map[i - 4][j] == 4)) && ((map[i - 3][j] == 1) || (map[i - 3][j] == 4)) && ((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i - 3][j] == 1) || (map[i - 3][j] == 4)) && ((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i - 2][j] == 1) || (map[i - 2][j] == 4)) && ((map[i - 1][j] == 1) || map[i - 1][j] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i - 1][j] == 1) || map[i - 1][j] == 4))
									{
										map1[i][j] += 20;
									}
									

								}
								if ((i + 4) < H)
								{
									if (((map[i + 4][j] == 1) || (map[i + 4][j] == 4)) && ((map[i + 3][j] == 1) || (map[i + 3][j] == 4)) && ((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i + 3][j] == 1) || (map[i + 3][j] == 4)) && ((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i + 2][j] == 1) || (map[i + 2][j] == 4)) && ((map[i + 1][j] == 1) || map[i + 1][j] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i + 1][j] == 1) || map[i + 1][j] == 4))
									{
										map1[i][j] += 20;
									}
								
								}

								if ((j - 4) > -1)			//横向
								{
									//堵黑棋
									if (((map[i][j - 4] == 1) || (map[i][j - 4] == 4)) && ((map[i][j - 3] == 1) || (map[i][j - 3] == 4)) && ((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i][j - 3] == 1) || (map[i][j - 3] == 4)) && ((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i][j - 2] == 1) || (map[i][j - 2] == 4)) && ((map[i][j - 1] == 1) || map[i][j - 1] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i][j - 1] == 1) || map[i][j - 1] == 4))
									{
										map1[i][j] += 20;
									}
									
								}
								if ((j + 4) < H)
								{
									if (((map[i][j + 4] == 1) || (map[i][j + 4] == 4)) && ((map[i][j + 3] == 1) || (map[i][j + 3] == 4)) && ((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i][j + 3] == 1) || (map[i][j + 3] == 4)) && ((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i][j + 2] == 1) || (map[i][j + 2] == 4)) && ((map[i][j + 1] == 1) || map[i][j + 1] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i][j + 1] == 1) || map[i][j + 1] == 4))
									{
										map1[i][j] += 20;
									}

									
								}

								if (((j - 4) > -1) && ((i - 4) > -1))		//  \向
								{
									//堵黑棋
									if (((map[i - 4][j - 4] == 1) || (map[i - 4][j - 4] == 4)) && ((map[i - 3][j - 3] == 1) || (map[i - 3][j - 3] == 4)) && ((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i - 3][j - 3] == 1) || (map[i - 3][j - 3] == 4)) && ((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i - 2][j - 2] == 1) || (map[i - 2][j - 2] == 4)) && ((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i - 1][j - 1] == 1) || map[i - 1][j - 1] == 4))
									{
										map1[i][j] += 20;
									}
									

								}
								if (((j + 4) < H) && ((i + 4) < H))
								{
									if (((map[i + 4][j + 4] == 1) || (map[i + 4][j + 4] == 4)) && ((map[i + 3][j + 3] == 1) || (map[i + 3][j + 3] == 4)) && ((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i + 3][j + 3] == 1) || (map[i + 3][j + 3] == 4)) && ((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i + 2][j + 2] == 1) || (map[i + 2][j + 2] == 4)) && ((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i + 1][j + 1] == 1) || map[i + 1][j + 1] == 4))
									{
										map1[i][j] += 20;
									}

									
								}

								if (((i - 4) > -1) && ((j + 4) < H))		//  /向
								{
									//堵黑棋
									if (((map[i - 4][j + 4] == 1) || (map[i - 4][j + 4] == 4)) && ((map[i - 3][j + 3] == 1) || (map[i - 3][j + 3] == 4)) && ((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i - 3][j + 3] == 1) || (map[i - 3][j + 3] == 4)) && ((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i - 2][j + 2] == 1) || (map[i - 2][j + 2] == 4)) && ((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i - 1][j + 1] == 1) || map[i - 1][j + 1] == 4))
									{
										map1[i][j] += 20;
									}
									
								}
								if (((i + 4) < H) && ((j - 4) > -1))
								{
									if (((map[i + 4][j - 4] == 1) || (map[i + 4][j - 4] == 4)) && ((map[i + 3][j - 3] == 1) || (map[i + 3][j - 3] == 4)) && ((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
									{
										map1[i][j] += 100000;
									}
									if (((map[i + 3][j - 3] == 1) || (map[i + 3][j - 3] == 4)) && ((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
									{
										map1[i][j] += 10000;
									}
									if (((map[i + 2][j - 2] == 1) || (map[i + 2][j - 2] == 4)) && ((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
									{
										map1[i][j] += 500;
									}
									if (((map[i + 1][j - 1] == 1) || map[i + 1][j - 1] == 4))
									{
										map1[i][j] += 20;
									}

									
								}
							}
						}
					}

					//int x = 0, y = 0;
					/*do
					{
						x = rand() % H;
						y = rand() % H;
					} while ((map[x][y] == 0) || (map[x][y] == 3));*/

					//int max = map1[0][0];
					for (int i = 0; i < H; i++)
					{
						for (int j = 0; j < H; j++)
						{
							if (map1[i][j] > max)
							{
								max = map1[i][j];
								x = i, y = j;
							}
						}
					}
					map[x][y] = 2;
					str[y][x] = r;
					r++;
					for (int i = 0;i <= 14;i++)
					{
						for (int r = 0;r <= 14;r++)
						{
							if (map[i][r] == 2)
							{
								arr[i][r] = 1;
								setfillcolor(WHITE);
								solidcircle(45 + i * 58, 45 + r * 58, 27);
							}
						}
					}

					check(x, y);
					break;
				default:   break;
				}
			}
			//fat = fat * (-1);
			if (bunch == 1)
			{
				break;
			}
		}
}

//void history()
//{
//	int jack = 1;
//	initgraph(900, 900);
//	setbkcolor(WHITE);
//	cleardevice();
//	IMAGE img2, img1;
//	loadimage(&img2, "./进入.jpg", 900, 900);
//	putimage(0, 0, &img2);
//	loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
//	putimage(0, 0, &img1);
//	for(int l=1;l<=r-1;l++)
//	{ 
//		for (int i = 0;i <= 14;i++)
//		{
//			for (int j = 0;j <= 14;j++)
//			{
//				if (str[i][j] == l)
//				{
//					if (jack == 1)
//					{
//						//下棋;
//						setfillcolor(BLACK);
//						solidcircle(45 + i * 58, 45 + j * 58, 27);
//						jack *= -1;
//					}
//					else
//					{
//						setfillcolor(WHITE);
//						solidcircle(45 + i * 58, 45 + j * 58, 27);
//						jack *= -1;
//					}
//				}
//			}
//		}
//	}
//	//closegraph();
//}

int fib(int n)
{
	if (1 == n)
		return 0;
	if (2 == n)
		return 1;
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
}

//兼
void  RJ1()
{
	//while (1)
		//{
	int pitch = 3;//循环与否判断        
	for (int i = 0;i <= 14;i++)
	{
		for (int j = 0;j <= 14;j++)
		{
			arr[i][j] = 0;
		}
	}
	initgraph(900, 900);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img2, img1;
	loadimage(&img2, "./进入.jpg", 900, 900);
	putimage(0, 0, &img2);
	loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
	putimage(0, 0, &img1);
	ini();
	putthat();
	setfillcolor(YELLOW);
	settextcolor(RED);
	settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
	setbkmode(OPAQUE);//用当前设置的背景
	if (fat == 1)
	{
		outtextxy(350, 300, "黑方胜利");
	}
	if (fat == -1)
	{
		outtextxy(350, 300, "白方胜利");
	}
	outtextxy(350, 400, "对局回放");
	outtextxy(350, 500, "退出游戏");
	//再新一局之前要先清空棋盘!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 350 && msg.x <= 567 && msg.y >= 8 * 58 + 45 && msg.y <= 9 * 58 + 45)//弄一个方块按钮更好！！！！！等会改
				{
					pitch = 0;
				}
				else if (msg.x >= 350 && msg.x <= 567 && msg.y >= 6 * 58 + 45 && msg.y <= 7 * 58 + 45)
				{
					//printf("我肝你拿");
					pitch = 1;
					//goto here;
					for (int i = 0;i <= 14;i++)
					{
						for (int k = 0;k <= 14;k++)
						{
							printf("%d   ", str[i][k]);
						}
						printf("\n");
					}

					initgraph(900, 900);
					setbkcolor(WHITE);
					cleardevice();
					IMAGE img2, img1;
					loadimage(&img2, "./进入.jpg", 900, 900);
					putimage(0, 0, &img2);
					loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
					putimage(0, 0, &img1);
					for (int j = 1;j <= 225;j++)
					{
						int s = fib(41);
						for (int i = 0;i <= 14;i++)
						{
							for (int k = 0;k <= 14;k++)
							{
								if (str[i][k] == j)
								{
									if (bbq == 1)
									{
										setfillcolor(BLACK);
										solidcircle(45 + k * 58, 45 + i * 58, 27);
										bbq *= -1;
									}
									else
									{
										setfillcolor(WHITE);
										solidcircle(45 + k * 58, 45 + i * 58, 27);
										bbq *= -1;
									}
								}
							}

						}
					}
					settextcolor(RED);
					settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
					setbkmode(OPAQUE);//用当前设置的背景
					outtextxy(350, 400, "回放结束");
					pitch = 1;
				}
				break;
			default:
				break;
			}
		}
		if (pitch != 3)
		{
			break;
		}
	}
	// getchar();
/*	if (pitch == 0)
	{
		break;
	}
}*/
}

//守
void RJ2()
{

	{
		//while (1)
			//{
		int pitch = 3;//循环与否判断        
		for (int i = 0;i <= 14;i++)
		{
			for (int j = 0;j <= 14;j++)
			{
				arr[i][j] = 0;
			}
		}
		initgraph(900, 900);
		setbkcolor(WHITE);
		cleardevice();
		IMAGE img2, img1;
		loadimage(&img2, "./进入.jpg", 900, 900);
		putimage(0, 0, &img2);
		loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
		putimage(0, 0, &img1);
		ini();
		putbut();
		setfillcolor(YELLOW);
		settextcolor(RED);
		settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
		setbkmode(OPAQUE);//用当前设置的背景
		if (fat == 1)
		{
			outtextxy(350, 300, "黑方胜利");
		}
		if (fat == -1)
		{
			outtextxy(350, 300, "白方胜利");
		}
		outtextxy(350, 400, "对局回放");
		outtextxy(350, 500, "退出游戏");
		//再新一局之前要先清空棋盘!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
		ExMessage msg;
		while (1)
		{
			if (peekmessage(&msg, EM_MOUSE))
			{
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					if (msg.x >= 350 && msg.x <= 567 && msg.y >= 8 * 58 + 45 && msg.y <= 9 * 58 + 45)//弄一个方块按钮更好！！！！！等会改
					{
						pitch = 0;
					}
					else if (msg.x >= 350 && msg.x <= 567 && msg.y >= 6 * 58 + 45 && msg.y <= 7 * 58 + 45)
					{
						//printf("我肝你拿");
						pitch = 1;
						//goto here;
						for (int i = 0;i <= 14;i++)
						{
							for (int k = 0;k <= 14;k++)
							{
								printf("%d   ", str[i][k]);
							}
							printf("\n");
						}

						initgraph(900, 900);
						setbkcolor(WHITE);
						cleardevice();
						IMAGE img2, img1;
						loadimage(&img2, "./进入.jpg", 900, 900);
						putimage(0, 0, &img2);
						loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
						putimage(0, 0, &img1);
						for (int j = 1;j <= 225;j++)
						{
							int s = fib(41);
							for (int i = 0;i <= 14;i++)
							{
								for (int k = 0;k <= 14;k++)
								{
									if (str[i][k] == j)
									{
										if (bbq == 1)
										{
											setfillcolor(BLACK);
											solidcircle(45 + k * 58, 45 + i * 58, 27);
											bbq *= -1;
										}
										else
										{
											setfillcolor(WHITE);
											solidcircle(45 + k * 58, 45 + i * 58, 27);
											bbq *= -1;
										}
									}
								}

							}
						}
						//settextcolor(RED);
						//settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
						//setbkmode(OPAQUE);//用当前设置的背景
						//outtextxy(350, 400, "回放结束");
						pitch = 1;
					}
					break;
				default:
					break;
				}
			}
			if (pitch != 3)
			{
				break;
			}
		}
		// getchar();
	/*	if (pitch == 0)
		{
			break;
		}
	}*/
	}
}


void RR()
{
	//while (1)
		//{
	int pitch = 3;//循环与否判断        
	for (int i = 0;i <= 14;i++)
	{
		for (int j = 0;j <= 14;j++)
		{
			arr[i][j] = 0;
		}
	}
	player = 'X';
	point = -1;
	initgraph(900, 900);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img2, img1;
	loadimage(&img2, "./进入.jpg", 900, 900);
	putimage(0, 0, &img2);
	loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
	putimage(0, 0, &img1);
	putit();
	setfillcolor(YELLOW);
	settextcolor(RED);
	settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
	setbkmode(OPAQUE);//用当前设置的背景
	if (point == 1)
	{
		outtextxy(350, 300, "黑方胜利");
	}
	if (point == -1)
	{
		outtextxy(350, 300, "白方胜利");
	}
	outtextxy(350, 400, "对局回放");
	//outtextxy(350, 400, "再来一局");
	outtextxy(350, 500, "退出游戏");
	//再新一局之前要先清空棋盘!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1		
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 350 && msg.x <= 567 && msg.y >= 6 * 58 + 45 && msg.y <= 7 * 58 + 45)
				{
					for (int i = 0;i <= 14;i++)
					{
						for (int k = 0;k <= 14;k++)
						{
							printf("%d   ", str[i][k]);
						}
						printf("\n");
					}
					initgraph(900, 900);
					setbkcolor(WHITE);
					cleardevice();
					IMAGE img2, img1;
					loadimage(&img2, "./进入.jpg", 900, 900);
					putimage(0, 0, &img2);
					loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
					putimage(0, 0, &img1);
					for (int j = 1;j <= 225;j++)
					{
						int s = fib(41);
						for (int i = 0;i <= 14;i++)
						{
							for (int k = 0;k <= 14;k++)
							{
								if (str[i][k] == j)
								{
									if (bbq == 1)
									{
										setfillcolor(BLACK);
										solidcircle(45 + k * 58, 45 + i * 58, 27);
										bbq *= -1;
									}
									else
									{
										setfillcolor(WHITE);
										solidcircle(45 + k * 58, 45 + i * 58, 27);
										bbq *= -1;
									}
								}
							}
							
						}
					}
					settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
					setbkmode(OPAQUE);//用当前设置的背景
					outtextxy(350, 400, "回放结束");
					pitch = 1;
				}
				else if (msg.x >= 350 && msg.x <= 567 && msg.y >= 8 * 58 + 45 && msg.y <= 9 * 58 + 45)//弄一个方块按钮更好！！！！！等会改
				{
					pitch = 0;
				}
				//else if (msg.x >= 350 && msg.x <= 567 && msg.y >= 6 * 58 + 45 && msg.y <= 7 * 58 + 45)
				//{
				//	//printf("我肝你拿");
				//	pitch = 1;
				//	//goto there;
				//	//history();
				//	
				//}
				break;
			default:
				break;
			}
		}
		if (pitch != 3)
		{
			break;
		}
	}
	// getchar();
/*	if (pitch == 0)
	{
		break;
	}
}*/
}


int main()
{
	//there:
	//BGM();
	//here:
	initgraph(900, 900);
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img2, img1;
	loadimage(&img2, "./进入.jpg", 900, 900);
	putimage(0, 0, &img2);
	loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
	putimage(0, 0, &img1);
	settextcolor(RED);
	settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
	setbkmode(OPAQUE);//用当前设置的背景
	outtextxy(350, 400, "人人对战");
	outtextxy(350, 500, "人机普通");
	outtextxy(350, 600, "人机进阶");
	int zlh = 3;
	//int jiance = 0;
	ExMessage msg2;
	while (1)
	{
		if (peekmessage(&msg2, EM_MOUSE))
		{
			switch (msg2.message)
			{
			case WM_LBUTTONDOWN:
				if (msg2.x >= 350 && msg2.x <= 567 && msg2.y >= 8 * 58 + 45 && msg2.y <= 9 * 58 + 45)//弄一个方块按钮更好！！！！！等会改
				{
					zlh = 0;
				}
				else if (msg2.x >= 350 && msg2.x <= 567 && msg2.y >= 6 * 58 + 45 && msg2.y <= 7 * 58 + 45)
				{
					//printf("我肝你拿");
					zlh = 1;
				}
				else if (msg2.x >= 350 && msg2.x <= 567 && msg2.y >= 9.5 * 58 + 45 && msg2.y <= 10.5 * 58 + 45)
				{
					//printf("我肝你拿");
					zlh = 2;
				}
				break;
			default:
				break;
			}
		}
		if (zlh != 3)
		{
			break;
		}
	}
	if (zlh == 0)//人机守
	{
		RJ2();
		


		
	}
	else if(zlh==1)//人人
	{
		RR();
		
	}
	else if (zlh == 2)//人人兼
	{
		RJ1();
		initgraph(900, 900);
		setbkcolor(WHITE);
		cleardevice();
		//IMAGE img2, img1;
		//loadimage(&img2, "./进入.jpg", 900, 900);
		putimage(0, 0, &img2);
		//loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
		putimage(0, 0, &img1);
		settextcolor(RED);
		settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
		setbkmode(OPAQUE);//用当前设置的背景
		outtextxy(350, 400, "回放结束");

	}
	closegraph();
    return 0;
}
