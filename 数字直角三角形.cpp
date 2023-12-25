#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m=1;
	for(int i=0;i<n;i++)
	{
		for(int k=0;k<n-i;k++)
		{
			printf("%02d",m);
			m++;
		}
		printf("\n");
	}
	return 0;
}