#include<stdio.h>
long long ar[1000100]={0};
long long maxt(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	long long t;
	scanf("%lld",&t);
	for(long long i=0;i<t;i++)
	{
		long long n;
		scanf("%lld",&n);
		for(long long j=0;j<n;j++)
		{
			scanf("%lld",&ar[j]);
		}
		long long sum=0;
//		for(long long j=0;j<n;j++)
//		{
//			for(long long k=j+1;k<n;k++)
//			{				
//				sum+=4*maxt(ar[j],ar[k]);
//			}
//		}
		long long tmp=0;
		for(long long j=0;j<n;j++)
		{
			for(long long k=0;k<n-1-j;k++)
			{
				if(ar[k]>ar[k+1])
				{
					tmp=ar[k];
					ar[k]=ar[k+1];
					ar[k+1]=tmp;
				}
			}
		}
		for(long long j=n-1;j>0;j--)
		{
			sum+=4*j*ar[j];
		}
		printf("%lld\n",sum);
	}
	return  0;
}