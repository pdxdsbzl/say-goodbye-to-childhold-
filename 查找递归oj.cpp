//int find(int m)
//{
//	int n;
//	int arr[n];
//	int left=0;
//	int right=n-1;
//	
//}
#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[n];
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<=n-1;i++)
	{
		if(arr[i]==m)
		{
			printf("%d",i);
			break;
		}
		if(i==n-1)
		{
			printf("-1");
			break;
		}
	}
	
}