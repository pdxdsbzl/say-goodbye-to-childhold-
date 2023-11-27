#include<stdio.h>
#include<math.h>
int main()
{
	int n,v;
	scanf("%d",&n);
	v=pow(2,n);
	int arr[v];
	for(int i=0;i<=v-1;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<=v-1;i++)
	{
		if(arr[i]<arr[0])
		{
			printf("%d",i);
			break;
		}
	}
	return 0;
}