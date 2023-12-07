#include<stdio.h>
int main()
{
	int n,sum1,sum2;
	scanf("%d",&n);
	sum1=5*n;
	sum2=11+3*n;
	if(sum1<sum2)
	printf("Local");
	else
	printf("Luogu");
}