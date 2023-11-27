//int f(int n)
//{
//	if(n>3)
//	return f(n-1)+f(n-2)+f(n-3);
//	else if(n==1)
//	return 1;
//	else if(n==2)
//	return 2;
//	else if(n==3)
//	return 4;
//}
//#include<stdio.h>
//int main()
//{
//	int n,m;
//	scanf("%d",&n);
//	m=f(n);
//	printf("%d",m);
//	return 0;
//}
int f(int n)
{
	int a=1;
	int b=2;
	int c=4;
	int tmp=0;
	if(n==1)
	return 1;
	if(n==2)
	return 2;
	if(n==3)
	return 4;
	else if(n>3)
	{
		while(n-3)
		{
			tmp=a+b+c;
			a=b;
			b=c;
			c=tmp;
			n--;//ATTENTION PLEASE!!!!!!DON'T LOST IT!!!!!!!!!!!!!!!
		}
		return tmp;
	}
}
#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	m=f(n);
	printf("%d",m);
	return 0;
}
