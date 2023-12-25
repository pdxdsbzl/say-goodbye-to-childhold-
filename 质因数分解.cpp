#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m=0;
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			m=i;
			break;
		}
	}
	printf("%d",n/m);
	return 0;
}