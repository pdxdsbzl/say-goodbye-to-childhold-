#include<stdio.h>
int main()
{
	int n,x,point=0;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		int m=i;
		while(1)
		{
			if(m>=10)
			{
				if(m%10==x)
				{
					point++;
				}
			}
			else
			{
				if(m==x)
				{
					point++;
				}
				break;
			}
			m/=10;
		}
	}
	printf("%d",point);
}