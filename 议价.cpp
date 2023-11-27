#include<stdio.h>
int main()
{
	int n=0;
	scanf("%d",&n);
	int arr1[n]={0};//chu shi hua???
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&arr1[i]);
	}
	int v=0;
	int sum=0;
	int u=0;
	for(int i=0;i<=n-1;i++)
	{
		int flag=0;
		for(int j=i+1;j<=n-i;j++)
		{
			if(arr1[i]==arr1[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		continue;
		int tmp=0;
		v=arr1[i];
		for(int k=0;k<=n-1;k++)
		{
			if(arr1[k]>=v)
			tmp+=v;
		}
		if(tmp>sum)
		{
			sum=tmp;
			u=v;
		}
		if(tmp==sum&&v<u)
		{
			u=v;
		}
	}
	printf("%d %d",sum,u);
	return 0;//错了，不一定要等于某物价格
}