#include<stdio.h>
int ar[10010]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
		for(int j=1;j<ar[i];j++)
		{
			printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}