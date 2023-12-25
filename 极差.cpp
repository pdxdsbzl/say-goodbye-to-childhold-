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
	int max=-10000,min=10000;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
		if(arr[i]<min)
		min=arr[i];
	}
	printf("%d",max-min);
	return 0;
}