#include<bits/stdc++.h>
long long gcd(long long a,long long b)
{
	int yue;
	for(int i=a;i>=1;i--)//从高到低循环，确保求得的是最大公约数（无需判断a，b的大小） 
	{
		if(a%i==0 && b%i==0)
		                 //判断是否可以同时整除
		{
			yue=i;
			break;       //跳出循环
		}
	}
	return a/yue;        //返回值 
}
int main()
{
	long long a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int tmp=0;
	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	if(b>c)
	{
		tmp=b;
		b=c;
		c=tmp;
	}
	if(a>b)
	{
		tmp=a;
		a=b;
		b=tmp;
	}
	printf("%d/%d",gcd(a,c),gcd(c,a));
}