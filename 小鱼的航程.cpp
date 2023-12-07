#include<stdio.h>
int main()
{
	int x,n;
	int s=0;
	scanf("%d%d",&x,&n);
	for(int i=1;i<=n;i++)
	{
		if(x==6)
		{
			x++;
			continue;
		}
		if(x==7)
		{
			x=1;
			continue;
		}
		s+=250;
		x++;
	}
	printf("%d",s);
	return 0;
}