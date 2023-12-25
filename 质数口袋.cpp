#include<stdio.h>
void putit(int l)
{
	int point=0;
	int sum=0;
	for(int i=2;;i++)
	{
		int flag=0;
		if(sum+i>l)
		{
			printf("%d",point);
			break;
		}
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			sum+=i;
			point++;
			printf("%d\n",i);
		}
	}
}
int main()
{
	int l;
	scanf("%d",&l);
	putit(l);
}