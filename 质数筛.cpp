#include<stdio.h>
int zhishu(int a)
{
	int flag=0;
	for(int i=2;i<=a-1;i++)
	{
		if(a%i==0)
		flag=1;
	}
	if(flag==1)
	{
		return 0;
	}
	else
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr1[n];
	int arr2[100];
	for(int i=0;i<=n-1;i++)
	{
		scanf("%d",&arr1[i]);
		if(zhishu(arr1[i])==1)
		printf("%d ",arr1[i]);
	}

}