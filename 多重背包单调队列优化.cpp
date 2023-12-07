#include <stdio.h>
#define N 20010
int dp1[N], dp[N], q[N];
int n, m;
int max(int a, int b) 
{
    return a > b ? a : b;
}
int main() 
{
    scanf("%d %d", &n, &m);//n为物品种类数，m为背包容量
    for (int i = 0; i < n; i++) 
	{
        for(int j = 0; j < N; j++) 
		{
            dp1[j] = dp[j];
        }
        int v, w, s;//v为重量，w为价值，s为数量
        scanf("%d %d %d", &v, &w, &s);
        for (int j = 0; j < v; j++) //j为各种余数
		{
            int h = 0, t = -1;
            for (int k = j; k <= m; k += v) 
			{
                if (h <= t && q[h] < k - v * s) 
				{
                    h++;
                }
                if (h <= t) 
				{
                    dp[k] = max(dp1[k], dp1[q[h]] + (k - q[h]) / v * w);
                }
                while (h <= t && dp1[k] >= dp1[q[t]] + (k - q[t]) / v * w) 
				{
                    t--;
                }
                q[++t] = k;
            }
        }
    }
    printf("%d", dp[m]);
    return 0;
}