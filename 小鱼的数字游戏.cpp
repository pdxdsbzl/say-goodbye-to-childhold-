#include<stdio.h>
int main()
{
	int arr[1000]={0};
	int flag=0;
	for(int i=0;;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]==0)
		{
			flag=i;
			break;
		}
	}
	for(int i=flag-1;i>=0;i--)
	{
		printf("%d ",arr[i]);
		
	}
	return 0;
}