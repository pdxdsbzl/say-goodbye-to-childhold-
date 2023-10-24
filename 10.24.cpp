#include<stdio.h>
int main()
{
	int n;
	int i;
	int x=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		x=x*i;	
	}
	printf("%d",x);
}