#include<stdio.h>
#include<math.h>
int jc(int n)
{
	if(n==1)
	return 1;
	if(n>1)
	return n*jc(n-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",jc(n));
	return 0;
}