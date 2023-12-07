//#include<stdio.h>
//int main()
//{
//	int n,m;
//	scanf("%d%d",&n,&m);
//	float arr[n][m];
//	for(int i=0;i<=n-1;i++)
//	{
//		for(int j=0;j<=m-1;j++)
//		{
//			scanf("%d",&arr[i][j]);
//		}
//	}
//	float pw[n];
//	int tmp=0;
//	for(int i=0;i<=n-1;i++)
//	{
//		for(int j=0;j<=m-2;j++)
//		{
//			for(int k=0;k<=m-2-j;k++)
//			{
//				if(arr[i][k]>arr[i][k+1])
//				{
//					tmp=arr[i][k];
//					arr[i][k]=arr[i][k+1];
//					arr[i][k+1]=tmp;
//				}
//			}
//		}
//		for(int u=1;u<=m-2;u++)
//		{
//			pw[i]+=(float)arr[i][u]/m;
//		}
//	}
////	for(int i=0;i<=n-1;i++)
////	{
////		printf("%f",pw[i]);
////	}//test
//	float tmp2=0.0;
//	for(int i=0;i<=n-1;i++)
//	{
//		if(pw[i]>tmp2)
//		tmp2=pw[i];
//	}
//	printf("%f",tmp2);
//}
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    float arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%f", &arr[i][j]);
        }
    }
    float pw[n];
    float tmp = 0.0;
    for (int i = 0; i < n; i++) {
        // 对每个同学的评分进行排序
        for (int j = 0; j < m-1; j++) {
            for (int k = 0; k < m-1-j; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    tmp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = tmp;
                }
            }
        }
        // 去掉最高分和最低分，计算平均分
        float sum = 0.0;
        for (int u = 1; u < m-1; u++) {
            sum += arr[i][u];
        }
        pw[i] = sum / (m - 2);
    }
    // 找到得分最高的同学
    float maxScore = 0.0;
    for (int i = 0; i < n; i++) {
        if (pw[i] > maxScore) {
            maxScore = pw[i];
        }
    }
    printf("%.2f\n", maxScore);
    return 0;
}