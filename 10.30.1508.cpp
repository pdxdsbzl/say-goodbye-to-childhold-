#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main() 
{
    int n, bag;//n为物体个数，bag为背包容量
    printf("\n请输入物体个数和背包容量：\n");
    scanf("%d %d",&n,&bag);
    int w[100];//每个物体重量
	int v[100];//每个物体价值
    printf("请依次输入每个物体的重量和价值：\n");
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
    }
	int maxvalue[100][100] = {0};//动态规划表
    //制表
	for (int i = 1; i <= n; i++) 
    {
		for (int wight = 1; wight <= bag; wight++)
        {
			if (wight < w[i])
				maxvalue[i][wight] = maxvalue[i-1][wight];
			else
				maxvalue[i][wight] = max(maxvalue[i-1][wight], maxvalue[i-1][wight-w[i]] + v[i]);
		}
	}
    //打表
    printf("w i g h t: ");
    for(int wight=1; wight <= bag; wight++) printf("%-3d", wight);
    printf("\n");
    for(int i = 1; i <= n; i++)
    {
        printf("w%d,v%-3di=%d ", w[i],v[i], i);
        for(int wight = 1; wight <= bag; wight++)
        {
            printf("%-3d", maxvalue[i][wight]);
        }
        printf("\n");
    }
    printf("\n");
    //输出最大值
    printf("MAX=%d\n", maxvalue[n][bag]);
    //最大值回溯
    int judge[100] = {0};
    int x = n, y = bag;
    while(x != 0 && y != 0)
    {
        if(maxvalue[x][y] != maxvalue[x-1][y])
        {
            judge[x]++;
            y-=w[x];
            x--;
        }
        else x--;
    }
    //输出满足条件的物体
    for(int i = 1; i <= n; i++)
    {
        if(judge[i]) printf("NO.%d wight%d value%d\n", i, w[i], v[i]);
    }
}
