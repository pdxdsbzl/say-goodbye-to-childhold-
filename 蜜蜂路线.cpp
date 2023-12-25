//#include<stdio.h>
//unsigned long long Fib(unsigned long long m,unsigned long long n)
//{
//	unsigned long long a=1;
//	unsigned long long b=2;
//	unsigned long long tmp=0;
//	unsigned long long u=n-m;
//	if(u==1)
//	{
//		return 1;
//	}
//	if(u==2)
//	{
//		return 2;
//	}
//		while(u-2)
//		{
//			tmp=a+b;
//			a=b;
//			b=tmp;
//			u--;
//		}
//		return tmp;
//}
//int main()
//{
//	unsigned long long m,n;
//	scanf("%llu%llu",&m,&n);
//	printf("%llu",Fib(m,n));
//	return 0;
//}





#include<stdio.h>
#include<string.h>
char s1[10010],s2[10010],s3[10010];
int a[10010],b[10010],c[10010];
int Fib(int m,int n)
{
	a[0]=1;
	b[0]=2;
	//c[0]=0;
	if(m-n==1)
	{
		printf("1");
		return 1;
	}
	if(m-n==2)
	{
		printf("2");
		return 2;
	}
	while((m-n)-2)
	{
		int la=strlen(a);
		int lb=strlen(b);
		int lc=la>lb?la:lb;
		for(int i=0;i<lc;i++)
		{
			c[i]+=a[i]+b[i];
			c[i+1]=c[i]/10;
			c[i]=c[i]%10;
		}
		strcpy(a,b);
		strcpy(b,c);
		(m-n)--;		
	}
	lc=strlen(c);
	for(int i=0;i<lc;i++)
	{
		printf("%d",c[i]);
	}
	return 0;
}
int main()
{
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	void Fib(m,n);
	return 0;
}