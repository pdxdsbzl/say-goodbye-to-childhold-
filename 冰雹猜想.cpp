#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[1000]={0};
	int point=0;
	for(int i=0;;i++)
	{
		if(n==1)
		{
			arr[i]=1;
			point=i;
			break;
		}
		if(n%2==0)
		{
			arr[i]=n;
			n/=2;
			continue;
		}
		if(n==1)
		{
			arr[i]=1;
			point=i;
			break;
		}
		if(n%2==1)
		{
			arr[i]=n;
			n=n*3+1;
			continue;
		}
	}
	for(int i=point;i>=0;i--)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}