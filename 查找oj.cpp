#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr1[n],arr2[m];
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&arr1[i]);
	}
	for(int i=0;i<=m-1;i++)
	{
		scanf("%d",&arr2[i]);
	}
	for(int i=0;i<=m-1;i++)
	{
		int left=0;
	    int right=n-1;
	while(1)
	{
        int middle=(left+right)/2;
		if(arr1[middle]==arr2[i])
		{
			printf("%d\n",middle);
			break;
		}
		if(arr1[middle]<arr2[i])
		{
			left=middle+1;
		}
		if(arr1[middle]>arr2[i])
		{
			right=middle-1;
		}
		if(left>right)
		{
			printf("-1\n");
			break;
		}
	}
	}
//	for(int i=0;i<=m-1;i++)
//	{
//		int flag=0;
//		for(int k=0;k<=n-1;k++)
//		{
//			if(arr2[i]==arr1[k])
//			{
//				flag=1;
//				printf("%d\n",k);
//				break;
//			}
//		}
//		if(flag==0)
//		{
//			printf("-1\n");
//		}
//	}

}