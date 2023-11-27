#include<stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	int v[n],w[n],s[n];
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d%d%d",&v[i],&w[i],&s[i]);//ATTENTION here v is jiazhi ！！xian shu ru v！！
	}
	int dp[c+1];
	for(int i=0;i<=c;i++)
	{
		dp[i]=0;//zhi jie ={0}?
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=c;j>=0;j--)
		{
			for(int k=0;k<=s[i]&&k*w[i]<=j;k++)
			{
				dp[j]=max(dp[j],dp[j-k*w[i]]+k*v[i]);
			}
		}
	}
	printf("%d",dp[c]);
	return 0;
}