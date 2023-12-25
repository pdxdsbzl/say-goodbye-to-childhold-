#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int x=100,k=1;
	int flag=0;
	for(k=1;;k++)
	{
		for(x=100;x>0;x--)
		{
			if(52*(7*x+21*k)==n)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		break;
	}
	printf("%d\n%d",x,k);
	return 0;
}