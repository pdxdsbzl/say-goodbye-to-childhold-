#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int tmp=10000;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<tmp)
		{
			tmp=arr[i];
		}
	}
	printf("%d",tmp);
}