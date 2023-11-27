#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[1000];
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&arr[i]);
	}
	int left=0;
	int right=n-1;
	while(1)
	{
        int middle=(left+right)/2;
		if(arr[middle]==m)
		{
			printf("%d",middle);
			break;
		}
		if(arr[middle]<m)
		{
			left=middle+1;
		}
		if(arr[middle]>m)
		{
			right=middle-1;
		}
		if(left>right)
		{
			printf("-1");
			break;
		}
	}
}