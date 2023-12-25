#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int max=0,min=10,sum=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		max=arr[i];
		if(arr[i]<min)
		min=arr[i];
		sum+=arr[i];
	}
	sum=sum-max-min;
	float p=(float)sum/(n-2);
	printf("%.2f",p);
	return 0;
}