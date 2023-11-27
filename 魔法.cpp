#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char str1[n];
	scanf("%s",&str1);
	int arr1[m][2];//chu shi hua????
	for(int i=0;i<=m-1;i++)
	{
		for(int k=0;k<=1;k++)
		{
			scanf("%d",&arr1[i][k]);
		}
	}
	for(int k=0;k<=m-1;k++)
	{
		int tmp=0;
		for(int j=arr1[k][0]-1;j<=arr1[k][1]-2;j++)
		{
			int point=0;
			for(int i=arr1[k][0];i<=arr1[k][1]-1;i++)
			{
				if(str1[j]==str1[i])
				{
					point+=1;
				}
			}
			if(tmp<point)
			{
				tmp=point;
			}
		}
		printf("%d\n",arr1[k][1]-arr1[k][0]-tmp);
	}
}