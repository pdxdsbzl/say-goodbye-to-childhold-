#include<stdio.h>
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	char str1[n+1][m];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m-1;j++)
		{
			scanf("%c",&str1[i][j]);
		}
	}
//	int sum=0;
//    int point=0;
//	for(int j=0;j<=n-1;j++)
//	{
//		point=0;
//		for(int i=0;i<=m-1;i++)
//		{
//			if(str1[j][i]==str1[n][i])
//			{
//				point+=1;
//			}
//		}
//		if((m-point)<=k)
//		{
//			sum+=1;
//		}
//	}
//	printf("%d",sum);
//    return 0;
}