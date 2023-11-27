int fib(int n)
{
	if(1==n)
	return 0;
	if(2==n)
	return 1;
	if(n>2)
	return fib(n-1)+fib(n-2);
}
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m=fib(n);
	printf("%d",m);
}