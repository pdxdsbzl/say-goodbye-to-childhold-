//#include<stdio.h>
//long long Fib(long long m,long long n)
//{
//	if(n-m==1)
//	{
//		return 1;
//	}
//	if(n-m==2)
//	{
//		return 2;
//	}
//	if(n-m>2)
//	{
//		return Fib(m,n-1)+Fib(m,n-2);
//	}
//}
//long long main()
//{
//	long long m,n;
//	scanf("%d%d",&m,&n);
//	printf("%d",Fib(m,n));
//	return 0;
//}
#include<stdio.h>
long long Fib(long long m,long long n)
{
	long long a=1;
	long long b=2;
	long long tmp=0;
	long long u=n-m;
	if(u==1)
	{
		return 1;
	}
	if(u==2)
	{
		return 2;
	}
		while(u-2)
		{
			tmp=a+b;
			a=b;
			b=tmp;
			u--;
		}
		return tmp;
}
int main()
{
	long long m,n;
	scanf("%lld%lld",&m,&n);
	printf("%lld",Fib(m,n));
	return 0;
}