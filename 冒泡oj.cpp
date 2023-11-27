
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
//	bubble(arr);
    int tmp=0;
    for(int i=0;i<=n-2;i++)
    {
    for(int k=0;k<=n-2;k++)
    {
    if(arr[k]>arr[k+1])
    {
    	tmp=arr[k];
    	arr[k]=arr[k+1];
    	arr[k+1]=tmp;
	}
    }
    }
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}