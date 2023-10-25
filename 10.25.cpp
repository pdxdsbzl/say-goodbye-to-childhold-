#include<stdio.h>
int main()
{
	int i;
	int sum=0;
	int n=1;
	int ret;
	int m;
	printf("please type a number 'm' here,then I will tell you the sum of 1!+2!+3!+...+m!\n");
	scanf("%d",&m);
	for(n=1;n<=m;n++)
	{
		ret=1;
		for(i=1;i<=n;i++)
		{
			ret=ret*i;
		}
		sum=sum+ret;
	}
	printf("%d",sum);
	return 0;
}