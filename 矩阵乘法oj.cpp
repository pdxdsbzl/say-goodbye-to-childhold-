#include<stdio.h>
#include<math.h>
int main()
{
	int sum,n,m;
	scanf("%d",&sum);
    int arr[sum][10][10][2];
	for(int i=0;i<=sum-1;i++)
	{
		scanf("%d%d",&n,&m);
		n=arr[i][0][0][0];
		m=arr[i][0][0][1];
		for(int j=0;j<=n-1;j++)
		{
			for(int k=0;k<=m-1;k++)
			{
				scanf("%d",&arr[i][j][k][0]);//also could use%s
			}
		}
	}
	int str[10][10];
	for(int i=0;i<=9;i++)
	{
		for(int k=0;k<=9;k++)
		{
			str[i][k]=1;
		}
	}
	for(int i=0;i<=sum-2;i++)//here sum-2?
	{
		if(arr[i][0][0][1]==arr[i+1][0][0][0])
		{
			for(int j=0;j<=arr[i][0][0][0]-1;j++)
			{
				for(int k=0;k<=arr[i+1][0][0][1]-1;k++)
				{
					for
					{
						str2=
					}
					str[j][k]=str[j][k]*arr[i][j][k][0]+str[j][k+1]*;
				}
			}
		}
		else
		printf("wrong");
		
	}
	printf("wrong");
}