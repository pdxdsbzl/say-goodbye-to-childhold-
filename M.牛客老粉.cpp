#include<stdio.h>
int main()
{
	int t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n=0;
		scanf("%d",&n);
		int point=0;
		if(n%6==0)
		{
			point=n/6;
		}
		else
		{
			point=n/6;
			point*=2;
		}
		printf("%d\n",point);
	}
	return 0;
}