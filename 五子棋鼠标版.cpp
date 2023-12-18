//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdbool.h>//0为空，1为黑，2为白,3为待选，4为13融合，5为23融合
//#include<graphics.h>
//#include<string.h>
//#include<mmsystem.h>
//#include<conio.h>
//#include<time.h>
//#define H 15
//#pragma comment(lib,"winmm.lib")
//#define BOARD_SIZE 15
// int arr[15][15] = { 0 };
// int m = 0;
// int n = 0;
// int row, col;
// char player = 'X';
// int point = -1;
//char board[BOARD_SIZE][BOARD_SIZE];
//void BGM()
//{
//	mciSendString("open ./原神之声.mp3", 0, 0, 0);
//	mciSendString("play ./原神之声.mp3 repeat", 0, 0, 0);//这里加上repeat可以重复播放
//	if (0)
//	{
//		mciSendString("close ./原神之声.mp3", 0, 0, 0);
//	}
//}
//void initBoard()
//{
//    for (int i = 0; i < BOARD_SIZE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE; j++)
//        {
//            board[i][j] = '.';
//        }
//    }
//}
//
//void printBoard()
//{
//    for (int i = 0; i < BOARD_SIZE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE; j++)
//        {
//            printf("%c ", board[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//bool isValidMove(int row, int col)
//{
//    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
//    {
//        return false;
//    }
//    if (board[row][col] != '.')
//    {
//        return false;
//    }
//    return true;
//}
//
//bool checkWin(int row, int col, char player)
//{
//    //    int dx[] = {-1, 0, 1, 1}; 
//    //    int dy[] = {0, 1, 1, -1};
//    int dx[] = { 1, 0, 1, -1 }; // 横、竖、斜、反斜四个方向
//    int dy[] = { 0, 1, 1, 1 };
//    for (int i = 0; i < 4; i++)
//    {
//        int count = 1;
//        int x = row + dx[i];
//        int y = col + dy[i];
//
//        while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == player)
//        {
//            count++;
//            x += dx[i];
//            y += dy[i];
//        }
//
//        x = row - dx[i];
//        y = col - dy[i];
//
//        while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == player)
//        {
//            count++;
//            x -= dx[i];
//            y -= dy[i];
//        }
//
//        if (count == 5)
//        {
//            return true;
//        }
//    }
//
//    return false;
//}
//
//bool isBoardFull()
//{
//    for (int i = 0; i < BOARD_SIZE; i++)
//    {
//        for (int j = 0; j < BOARD_SIZE; j++)
//        {
//            if (board[i][j] == '.')
//            {
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
////void playGame()
////{
////    char player = 'X';
////    initBoard();
////    printBoard();
////  //  while (true)
////  //  {
////        printf("Player %c's turn, enter row (0-%d) and column (0-%d): ", player, BOARD_SIZE - 1, BOARD_SIZE - 1);
////       // scanf("%d %d", &row, &col);
////        row = m;
////        col = n;
////        if (!isValidMove(row, col))
////        {
////            printf("Invalid move, try again.\n");
////            continue;
////        }
////
////        board[row][col] = player;
////        printBoard();//Here we can add qing kong 
////
////        if (checkWin(row, col, player))
////        {
////            printf("Player %c wins!\n", player);
////            break;
////        }
////
////        if (isBoardFull())
////        {
////            printf("It's a draw!\n");
////            break;
////        }
////
////        player = (player == 'X') ? 'O' : 'X';
////   //}
////}
//
//void putit()
//{
//        ExMessage msg;
//        initBoard();
//        printBoard();
//        int flag = 0;
//        while (1)
//        {
//            if (flag == 1)
//            {
//                /*settextcolor(RED);                
//                outtextxy(400, 400, "游戏结束！！");*/
//                break;
//            }
//            if (peekmessage(&msg, EM_MOUSE))
//            {
//                
//                 m = (msg.x -45)/ 58;
//                 n = (msg.y-45) / 58;
//                        switch (msg.message)//注意啊，这里的break都是跳出switch，吓死我了，还以为是while
//                        {
//                        case WM_LBUTTONDOWN:
//                            if ((msg.x - 45) % 58 <= 28 && (msg.y - 45) % 58 <=28)
//                            {
//                                if (arr[m][n] == 1)
//                                {
//                                    	HWND hnd = GetHWnd();	
//                                        SetWindowText(hnd, "五子棋启动");
//	                                    int isok=MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
//                                    break;
//                                }
//                                if (point ==1)
//                                {//printf("我是按钮我被点了");
//                                    setfillcolor(WHITE);
//                                    solidcircle(45+m*58, 45+n*58, 27);
//                                    point *= -1;
//                                }
//                                else
//                                {
//                                    setfillcolor(BLACK);
//                                    solidcircle(45+m*58, 45+n*58, 27);
//                                    point *= -1;
//                                }
//                                arr[m][n] = 1;
//                            }
//                            else  if ((msg.x - 45) % 58 > 28 && (msg.y - 45) % 58 <=28)
//                            {
//                                m += 1;
//                                if (arr[m][n] == 1)
//                                {
//                                    HWND hnd = GetHWnd();
//                                    SetWindowText(hnd, "五子棋启动");
//                                    int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
//                                    break;
//                                }
//                                if (point == 1)
//                                {//printf("我是按钮我被点了");
//                                    setfillcolor(WHITE);                                    
//                                    solidcircle(45 + m* 58, 45 + n * 58, 27);
//                                    point *= -1;
//                                }
//                                else
//                                {
//                                    setfillcolor(BLACK);
//                                    solidcircle(45 + m * 58, 45 + n * 58, 27);
//                                    point *= -1;
//                                }
//                                arr[m][n] = 1;
//                            }
//                            else  if ((msg.x - 45) % 58 <=28 && (msg.y - 45) % 58 >28)
//                            {
//                                n += 1;
//                                if (arr[m ][n] == 1)
//                                {
//                                    HWND hnd = GetHWnd();
//                                    SetWindowText(hnd, "五子棋启动");
//                                    int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
//                                    break;
//                                }
//                                if (point == 1)
//                                {//printf("我是按钮我被点了");
//                                    setfillcolor(WHITE);
//                                    solidcircle(45 + m * 58, 45 +n * 58, 27);
//                                    point *= -1;
//                                }
//                                else
//                                {
//                                    setfillcolor(BLACK);
//                                    solidcircle(45 + m * 58, 45 + n * 58, 27);
//                                    point *= -1;
//                                }
//                                arr[m][n] = 1;
//                            }
//                            else  if ((msg.x - 45) % 58 >28&& (msg.y - 45) % 58 > 28)
//                            {
//                                m += 1;
//                                n += 1;
//                                if (arr[m][n] == 1)
//                                {
//                                    HWND hnd = GetHWnd();
//                                    SetWindowText(hnd, "五子棋启动");
//                                    int isok = MessageBox(hnd, "你下在了重复的位置，请重新下！", "提示", MB_OKCANCEL);
//                                    break;
//                                }
//                                if (point == 1)
//                                {//printf("我是按钮我被点了");
//                                    setfillcolor(WHITE);
//                                    solidcircle(45 +m * 58, 45 + n * 58, 27);
//                                    point *= -1;
//                                }
//                                else
//                                {
//                                    setfillcolor(BLACK);
//                                    solidcircle(45 + m * 58, 45 + n* 58, 27);
//                                    point *= -1;
//                                }
//                                arr[m][n] = 1;
//                            }                         
//                            printf("Player %c's turn, enter row (0-%d) and column (0-%d): ", player, BOARD_SIZE - 1, BOARD_SIZE - 1);
//                            // scanf("%d %d", &row, &col);
//                            row = n;//这里千万注意！！！！两个的列与行是反的！！！！！
//                            col = m;                                                        
//                            if (!isValidMove(row, col))
//                            {
//                                printf("Invalid move, try again.\n");
//                                continue;
//                            }                           
//                            board[row][col] = player;
//                            printBoard();//Here we can add qing kong 
//
//                            if (checkWin(row, col, player))
//                            {
//                                flag = 1;
//                                printf("Player %c wins!\n", player);
//                                break;
//                            }
//
//                            if (isBoardFull())
//                            {
//                                printf("It's a draw!\n");
//                                break;
//                            }
//
//                            player = (player == 'X') ? 'O' : 'X';
//                            break;
//                        default:   break;
//                        }
//            }
//        }
//}
//int main()
//{
//    while (1)
//    {
//        int pitch = 3;//循环与否判断
//        //BGM();
//        for (int i = 0;i <= 14;i++)
//        {
//            for (int j = 0;j <= 14;j++)
//            {
//                arr[i][j] = 0;
//            }
//        }
//        player = 'X';
//        point = -1;
//        initgraph(900, 900);
//        setbkcolor(WHITE);
//        cleardevice();
//        IMAGE img2, img1;
//        loadimage(&img2, "./进入.jpg", 900, 900);
//        putimage(0, 0, &img2);
//        loadimage(&img1, "./棋盘2.0版本.jpg", 900, 900);
//        putimage(0, 0, &img1);
//        putit();
//        setfillcolor(YELLOW);
//        //fillrectangle(300, 250, 600, 320);
//        //fillrectangle(300, 350, 600, 420);
//        //fillrectangle(300, 450, 600, 520);
//        settextcolor(RED);
//        settextstyle(50, 0, "宋体");//字体高度为50  宽度自适应
//        setbkmode(OPAQUE);//用当前设置的背景
//        if (point == 1)
//        {
//            outtextxy(350, 300, "黑方胜利");
//        }
//        if (point == -1)
//        {
//            outtextxy(350, 300, "白方胜利");
//        }
//        outtextxy(350, 400, "再来一局");
//        outtextxy(350, 500, "退出游戏");
//        //再新一局之前要先清空棋盘!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
//        ExMessage msg;
//        	while(1)
//        	{
//                if (peekmessage(&msg, EM_MOUSE))
//                {
//                    switch (msg.message)
//                    {
//                    case WM_LBUTTONDOWN:
//                        if (msg.x >= 350 && msg.x <=567 && msg.y >= 8*58+45 && msg.y <= 9*58+45)//弄一个方块按钮更好！！！！！等会改
//                        {
//                            pitch = 0;
//                        }
//                        else if (msg.x >= 350 && msg.x <= 567 && msg.y >= 6 * 58 + 45 && msg.y <= 7 * 58 + 45)
//                        {
//                            //printf("我肝你拿");
//                            pitch = 1;
//                        }
//                        break;
//                    default:
//                        break;
//                    }
//                }
//                if (pitch!=3)
//                {
//                    break;
//                }
//               }
//       // getchar();
//            if (pitch == 0)
//            {
//                break;
//            }
//    }
//    closegraph();
//    return 0;
//}
