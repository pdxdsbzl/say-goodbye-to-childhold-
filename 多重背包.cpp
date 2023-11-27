#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N, V;
    scanf("%d %d", &N, &V); // N为物品数量，V为背包容量
    int weight[N], value[N], count[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &weight[i], &value[i], &count[i]);
    }

    int dp[V + 1];
    for (int i = 0; i <= V; i++) 
	{
        dp[i] = 0;
    }
    for (int i = 0; i < N; i++)
	{
        for (int j = V; j >= 0; j--)
		{
            for (int k = 0; k <= count[i] && k * weight[i] <= j; k++) 
			{
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }
        }
    }
    printf("最大价值为: %d\n", dp[V]);
    return 0;
}
