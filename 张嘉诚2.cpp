#include<stdio.h>
int arr[100][100]={0};
int b[100][100]={0};
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==0)
			{
				b[i][j]=1;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(b[i][j]==1)
			{
				for(int k=0;k<n;k++)
				{
					arr[i][k]=0;
				}
				for(int k=0;k<n;k++)
				{
					arr[k][j]=0;
				}
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}