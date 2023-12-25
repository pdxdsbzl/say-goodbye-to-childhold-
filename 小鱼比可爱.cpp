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
	int point=0;
	for(int i=0;i<n;i++)
	{
		point=0;
		for(int j=0;j<=i;j++)
		{
			if(arr[j]<arr[i])
			{
				point++;
			}
		}
		printf("%d ",point);
	}
	return 0;
}